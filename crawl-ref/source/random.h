#ifndef RANDOM_H
#define RANDOM_H

#include <map>
#include <vector>
#include "hash.h"

void seed_rng();
void seed_rng(uint32_t seed);

bool coinflip();
int div_rand_round(int num, int den);
int div_round_up(int num, int den);
bool one_chance_in(int a_million);
bool x_chance_in_y(int x, int y);
int random2(int max);
int maybe_random2(int x, bool random_factor);
int maybe_random_div(int nom, int denom, bool random_factor);
int maybe_roll_dice(int num, int size, bool random);
int random_range(int low, int high);
int random_range(int low, int high, int nrolls);
uint32_t random_int();
double random_real();
double random_real_inc();
double random_real_avg(int rolls);
double random_range_real(double low, double high, int nrolls = 1);

int random2avg(int max, int rolls);
int bestroll(int max, int rolls);
int biased_random2(int max, int n);
int random2limit(int max, int limit);
int binomial_generator(unsigned n_trials, unsigned trial_prob);
bool bernoulli(double n_trials, double trial_prob);
int fuzz_value(int val, int lowfuzz, int highfuzz, int naverage = 2);
int roll_dice(int num, int size);

int ui_random(int max);

/**
 * Chooses one of the numbers passed in at random. The list of numbers
 * must be terminated with -1.
 */
template <typename T>
T random_choose(T first, ...)
{
    va_list args;
    va_start(args, first);

    T chosen = first;
    int count = 1;
    int nargs = 100; // a hard limit to catch unterminated uses

    while (nargs-- > 0)
    {
        const int pick = va_arg(args, int);
        if (pick == -1)
            break;
        if (one_chance_in(++count))
            chosen = static_cast<T>(pick);
    }

    va_end(args);
    ASSERT(nargs > 0);
    return chosen;
}

template <>
const char* random_choose<const char*>(const char* first, ...);

template <typename T>
T random_choose_weighted(int weight, T first, ...)
{
    va_list args;
    va_start(args, first);
    T chosen = first;
    int cweight = weight, nargs = 100;

    while (nargs-- > 0)
    {
        const int nweight = va_arg(args, int);
        if (!nweight)
            break;

        const int choice = va_arg(args, int);
        if (random2(cweight += nweight) < nweight)
            chosen = static_cast<T>(choice);
    }

    va_end(args);
    ASSERT(nargs > 0);

    return chosen;
}

const char* random_choose_weighted(int weight, const char* first, ...);

struct dice_def
{
    int num;
    int size;

    dice_def(int n = 0, int s = 0) : num(n), size(s) {}
    int roll() const;
};

dice_def calc_dice(int num_dice, int max_damage);
void scale_dice(dice_def &dice, int threshold = 24);

template <typename T>
void shuffle_array(T* arr, int n)
{
    while (n > 1)
    {
        int i = random2(n);
        n--;
        T tmp = arr[i];
        arr[i] = arr[n];
        arr[n] = tmp;
    }
}

template <typename T>
void shuffle_array(vector<T> &vec)
{
    // &vec[0] is undefined behaviour, and vec.data() is C++11-only.
    if (!vec.empty())
        shuffle_array(&vec[0], vec.size());
}

/**
 * A defer_rand object represents an infinite tree of random values, allowing
 * for a much more functional approach to randomness.  defer_rand values which
 * have been used should not be copy-constructed.  Querying the same path
 * multiple times will always give the same result.
 *
 * An important property of defer_rand is that, except for rounding,
 * `float(r.random2(X)) / X == float(r.random2(Y)) / Y` for all `X` and `Y`.
 * In other words:
 *
 * - The parameter you use on any given call does not matter.
 * - The object stores the fraction, not a specific integer.
 * - random2() is monotonic in its argument.
 *
 * Rephrased: The first time any node in the tree has a method called on
 * it, a random float between 0 and 1 (the fraction) is generated and stored,
 * and this float is combined with the method's parameters to arrive at
 * the result.  Calling the same method on the same node with the same
 * parameters will always give the same result, while different parameters
 * or methods will give different results (though they'll all use the same
 * float which was generated by the first method call).  Each node in the
 * tree has it's own float, so the same method+parameters on different
 * nodes will get different results.
 */
class defer_rand
{
    vector<uint32_t> bits;
    map<int, defer_rand> children;

    bool x_chance_in_y_contd(int x, int y, int index);
public:
    // TODO It would probably be a good idea to have some sort of random
    // number generator API, and the ability to pass RNGs into any function
    // that wants them.
    bool x_chance_in_y(int x, int y) { return x_chance_in_y_contd(x,y,0); }
    bool one_chance_in(int a_million) { return x_chance_in_y(1,a_million); }
    int random2(int maxp1);

    int random_range(int low, int high);
    int random2avg(int max, int rolls);

    defer_rand& operator[] (int i);
};

template<typename Iterator>
int choose_random_weighted(Iterator beg, const Iterator end)
{
    ASSERT(beg < end);

#ifdef DEBUG
    int times_set = 0;
#endif

    int totalweight = 0;
    int count = 0, result = 0;
    while (beg != end)
    {
        totalweight += *beg;
        if (random2(totalweight) < *beg)
        {
            result = count;
#ifdef DEBUG
            times_set++;
#endif
        }
        ++count;
        ++beg;
    }
#ifdef DEBUG
    ASSERT(times_set > 0);
#endif
    return result;
}

#endif
