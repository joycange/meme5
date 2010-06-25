/*
 *  File:       dgn-actions.cc
 *  Summary:    Delayed level actions.
 *  Written by: Adam Borowski
 */

#include "AppHdr.h"

#include "dgn-actions.h"

#include "debug.h"
#include "env.h"
#include "player.h"

static const char *daction_names[] =
{
    "shuffle decks",
};

void add_daction(daction_type act)
{
    COMPILE_CHECK(ARRAYSZ(daction_names) == NUM_DACTIONS, dactions_names_size);

    dprf("scheduling delayed action: %s", daction_names[act]);
    you.dactions.push_back(act);

    // Immediately apply it to the current level.
    catchup_dactions();
}

void _apply_daction(daction_type act)
{
    ASSERT(act >= 0 && act < NUM_DACTIONS);
    dprf("applying delayed action: %s", daction_names[act]);
}

void catchup_dactions()
{
    while(env.dactions_done < you.dactions.size())
        _apply_daction(you.dactions[env.dactions_done++]);
}
