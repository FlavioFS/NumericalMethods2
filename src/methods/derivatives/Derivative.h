#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include "../../../src/includes/point.h"
#include "../../../src/common/Function.h"
#include <vector>

/*______________________________________________________________________________________
    
    Numeric Derivative Class
    HOW TO USE:
    ..................................................................................

    double f0(double x) { return (3*x*x*x); }

    Function f (f0);
    double
        value = 3,
        spacing = 0.1;

    cout << setprecision(20) << Derivative::backDiff(f0, value, spacing, true) << endl;
    cout << setprecision(20) << Derivative::forwDiff(f0, value, spacing, true) << endl;
    cout << setprecision(20) << Derivative::centDiff(f0, value, spacing, true) << endl;

    cout << setprecision(20) << Derivative::backDiffSecond(f0, value, spacing) << endl;
    cout << setprecision(20) << Derivative::forwDiffSecond(f0, value, spacing) << endl;
    cout << setprecision(20) << Derivative::centDiffSecond(f0, value, spacing) << endl << endl;

    // Result
    80.9400000000002251
    80.939999999999940883
    81.000000000000127898

    52.200000000001971046
    55.800000000000686384
    53.999999999999197087

    // Real value:
    f(x) = 3*x^3 => f'(x) = 9*x^2 => f'(3) = 9*(3^2) => f'(3) = 81

    ..................................................................................

    std::vector<point> sample;
    point
        p0 = {0, 153},
        p1 = {1.04, 208},
        p2 = {1.75, 249};

    sample.push_back(p0);
    sample.push_back(p1);
    sample.push_back(p2);

    cout << setprecision(20) << Derivative::lagrangeDiff(sample, 1.5) << endl;

    // Result
    58.329902491874328518
  ______________________________________________________________________________________*/

class Derivative
{
    public:
        /* ==========================================================
        		                 Static Methods
		========================================================== */
		// First Derivative - Intervals equally spaced
        static double backDiff(Function f, double value, double spacing, bool higher_precision);    // [1]
        static double forwDiff(Function f, double value, double spacing, bool higher_precision);    // [2]
        static double centDiff(Function f, double value, double spacing, bool higher_precision);    // [3]

        // First Derivative - Intervals randomly spaced
        static double lagrangeDiff(std::vector<point> function, double value);  // [4]

        // Second Derivative - Intervals equally spaced
        static double backDiffSecond(Function f, double value, double spacing); // [5]
        static double forwDiffSecond(Function f, double value, double spacing); // [6]
        static double centDiffSecond(Function f, double value, double spacing); // [7]

        // Richardson
        static double backRichardson(Function f, double value, double spacing, bool higher_precision); // [8]
        static double forwRichardson(Function f, double value, double spacing, bool higher_precision); // [9]
        static double centRichardson(Function f, double value, double spacing, bool higher_precision); // [10]
};

#endif // DERIVATIVE_H
