#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include "../../../src/includes/point.h"
#include "../../../src/common/Function.h"
#include <vector>

/*______________________________________________________________________________________
    
    Derivative class
    How to use:
  
    double f0(double x) { return (3*x*x*x); }
    Function f;
    f.setFunction(f0);

    double
        value = 3,
        spacing = 0.1;

    cout << setprecision(20) << Derivative::backDiff(f0, value, spacing, true) << endl;
    cout << setprecision(20) << Derivative::forwDiff(f0, value, spacing, true) << endl;
    cout << setprecision(20) << Derivative::centDiff(f0, value, spacing, true) << endl;

    // Result
	80.9400000000002251
	80.939999999999940883
	81.000000000000127898

	// Real value:
	f(x) = 3*x^3 => f'(x) = 9*x^2 => f'(3) = 9*(3^2) => f'(3) = 81
  ______________________________________________________________________________________*/

class Derivative
{
    public:
        /* ==========================================================
        		                 Static Methods
		========================================================== */
		// Intervals equally spaced
        static double backDiff(Function f, double value, double spacing, bool higher_precision);	// [1]
        static double forwDiff(Function f, double value, double spacing, bool higher_precision);	// [2]
        static double centDiff(Function f, double value, double spacing, bool higher_precision);	// [3]

        // Intervals randomly spaced
        static double backDiffRandom(std::vector<point> function);	// [4]
        static double forwDiffRandom(std::vector<point> function);	// [5]
        static double centDiffRandom(std::vector<point> function);	// [6]
};

#endif // DERIVATIVE_H
