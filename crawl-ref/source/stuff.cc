/**
 * @file
 * @brief Misc stuff.
**/

#include "AppHdr.h"
#include "stuff.h"

#include <cstdarg>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#include "abyss.h"
#include "cio.h"
#include "colour.h"
#include "crash.h"
#include "database.h"
#include "delay.h"
#include "dungeon.h"
#include "files.h"
#include "hints.h"
#include "libutil.h"
#include "los.h"
#include "macro.h"
#include "menu.h"
#include "message.h"
#include "notes.h"
#include "options.h"
#include "output.h"
#include "player.h"
#include "state.h"
#include "traps.h"
#include "view.h"
#include "viewchar.h"
#include "viewgeom.h"

#ifdef TOUCH_UI
#include "tilepick.h"
#include "tiledef-gui.h"
#endif

#ifdef __ANDROID__
#include <android/log.h>
double log2(double n)
{
    return log(n) / log(2); // :(
}
#endif

// Crude, but functional.
string make_time_string(time_t abs_time, bool terse)
{
    const int days  = abs_time / 86400;
    const int hours = (abs_time % 86400) / 3600;
    const int mins  = (abs_time % 3600) / 60;
    const int secs  = abs_time % 60;

    string buff;
    if (days > 0)
    {
        buff += make_stringf("%d%s ", days, terse ? ","
                             : days > 1 ? "days" : "day");
    }
    return buff + make_stringf("%02d:%02d:%02d", hours, mins, secs);
}

string make_file_time(time_t when)
{
    if (tm *loc = TIME_FN(&when))
    {
        return make_stringf("%04d%02d%02d-%02d%02d%02d",
                 loc->tm_year + 1900,
                 loc->tm_mon + 1,
                 loc->tm_mday,
                 loc->tm_hour,
                 loc->tm_min,
                 loc->tm_sec);
    }
    return "";
}

double stepdown(double value, double step)
{
    return step * log2(1 + value / step);
}

int stepdown(int value, int step, rounding_type rounding, int max)
{
    double ret = stepdown((double) value, double(step));

    if (max > 0 && ret > max)
        return max;

    // Randomised rounding
    if (rounding == ROUND_RANDOM)
    {
        double intpart;
        double fracpart = modf(ret, &intpart);
        if (decimal_chance(fracpart))
            ++intpart;
        return intpart;
    }

    return ret + (rounding == ROUND_CLOSE ? 0.5 : 0);
}

// Deprecated definition. Call directly stepdown instead.
int stepdown_value(int base_value, int stepping, int first_step,
                   int last_step, int ceiling_value)
{
    UNUSED(last_step);

    // Disabling max used to be -1.
    if (ceiling_value < 0)
        ceiling_value = 0;

    if (ceiling_value && ceiling_value < first_step)
        return min(base_value, ceiling_value);
    if (base_value < first_step)
        return base_value;

    const int diff = first_step - stepping;
    // Since diff < first_step, we can assume here that ceiling_value > diff
    // or ceiling_value == 0.
    return diff + stepdown(base_value - diff, stepping, ROUND_DOWN,
                           ceiling_value ? ceiling_value - diff : 0);
}
