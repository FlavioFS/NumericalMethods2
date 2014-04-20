#include "Derivative.h"
#include <cmath>
#include <iostream>

#define EXCEPTION_B_DIFF_SIZE "Exception: Backward Difference small sample exception"
#define EXCEPTION_F_DIFF_SIZE "Exception: Forward Difference small sample exception"
#define EXCEPTION_C_DIFF_SIZE "Exception: Central Difference small sample exception"

/* ==========================================================
                        Static Methods
========================================================== */

/* --------- Equally spaced derivatives --------- */
// [1] - Backward Difference
double Derivative::backDiff (Function f, double value, double spacing, bool higher_precision)
{
    double
        rear1 = value -   spacing,
        rear2 = value - 2*spacing;

    if (higher_precision)
    {
        return ( 3*f.run(value) - 4*f.run(rear1) + f.run(rear2) ) / (2*spacing);
    }

    return ( f.run(value) - f.run(rear1) ) / spacing;
}

// [2] - Forward Difference
double Derivative::forwDiff (Function f, double value, double spacing, bool higher_precision)
{
    double
        front1 = value +   spacing,
        front2 = value + 2*spacing;

    if (higher_precision)
    {
        return ( -f.run(front2) + 4*f.run(front1) - 3*f.run(value) ) / (2*spacing);
    }

    return ( f.run(front1) - f.run(value) ) / spacing;
}

// [3] - Central Difference
double Derivative::centDiff (Function f, double value, double spacing, bool higher_precision)
{
    double
        rear1  = value -   spacing,
        rear2  = value - 2*spacing,
        front1 = value +   spacing,
        front2 = value + 2*spacing;

    if (higher_precision)
    {
        return ( -f.run(front2) + 8*f.run(front1) - 8*f.run(rear1) + f.run(rear2) ) / (12*spacing);
    }

    return ( f.run(front1) - f.run(rear1) ) / (2*spacing);
}

/* --------- Randomly spaced derivatives --------- */
// [4] - Backward Difference
double Derivative::backDiffRandom (std::vector<point> function)
{
    if ( function.size() >= 3 )
    {
        return 0;
    }

    std::cout << EXCEPTION_B_DIFF_SIZE;
    throw        EXCEPTION_B_DIFF_SIZE;
}

// [5] - Forward Difference
double Derivative::forwDiffRandom (std::vector<point> function)
{
    if ( function.size() >= 3 )
    {
        return 0;
    }

    std::cout << EXCEPTION_F_DIFF_SIZE;
    throw        EXCEPTION_F_DIFF_SIZE;
}

// [6] - Central Difference
double Derivative::centDiffRandom (std::vector<point> function)
{
    if ( function.size() >= 3 )
    {
        return 0;
    }

    std::cout << EXCEPTION_C_DIFF_SIZE;
    throw        EXCEPTION_C_DIFF_SIZE;
}
