#include "Derivative.h"
#include <cmath>
#include <iostream>

#define EXCEPTION_B_DIFF_SIZE "Exception: Backward Difference small sample exception"
#define EXCEPTION_F_DIFF_SIZE "Exception: Forward Difference small sample exception"
#define EXCEPTION_C_DIFF_SIZE "Exception: Central Difference small sample exception"

/* ==========================================================
                        Static Methods
========================================================== */

/* --------- First Derivative - Equally Spaced --------- */
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


/* --------- Lagrange Derivative - Randomly Spaced --------- */
// [4] - Backward Difference
double Derivative::lagrangeDiff (std::vector<point> function, double value)
{   
    if ( function.size() == 3 )
    {
        double lagrange = 0;

        lagrange += function[0].y*(2*value - function[1].x - function[2].x) /
                  ( (function[0].x - function[1].x)*(function[0].x - function[2].x) );

        lagrange += function[1].y*(2*value - function[0].x - function[2].x) /
                  ( (function[1].x - function[0].x)*(function[1].x - function[2].x) );

        lagrange += function[2].y*(2*value - function[0].x - function[1].x) /
                  ( (function[2].x - function[0].x)*(function[2].x - function[1].x) );

        return lagrange;
    }

    std::cout << EXCEPTION_B_DIFF_SIZE;
    throw        EXCEPTION_B_DIFF_SIZE;
}


/* --------- Second Derivative - Equally Spaced --------- */
// [5] - Backward Difference
double Derivative::backDiffSecond (Function f, double value, double spacing)
{
    double
        rear1 = value -   spacing,
        rear2 = value - 2*spacing;

    return ( f.run(value) - 2*f.run(rear1) + f.run(rear2) ) / (spacing*spacing);
}

// [6] - Forward Difference
double Derivative::forwDiffSecond (Function f, double value, double spacing)
{
    double
        front1 = value +   spacing,
        front2 = value + 2*spacing;

    return ( f.run(front2) - 2*f.run(front1) + f.run(value) ) / (spacing*spacing);
}

// [7] - Central Difference
double Derivative::centDiffSecond (Function f, double value, double spacing)
{
    double
        rear1  = value -   spacing,
        front1 = value +   spacing;

    return ( f.run(front1) - 2*f.run(value) + f.run(rear1) ) / (spacing*spacing);
}
