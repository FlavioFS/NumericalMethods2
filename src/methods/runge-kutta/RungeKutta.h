#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

#include <vector>
#include "../../includes/point.h"
#include "../../common/FunctionRn.h"

class RungeKutta
{
    public:
    	  
        static std::vector<point> firstOrder (FunctionRn f, double v0, double h, double left, double right);

        // [1] - Second Order Runge Kutta
        static std::vector<point> secondOrder (FunctionRn f, double v0, double h, double left, double right);

        // [2] - Third Order Runge Kutta
		static std::vector<point> thirdOrder (FunctionRn f, double v0, double h, double left, double right);

		// [3] - Fourth Order Runge Kutta
		static std::vector<point> fourthOrder (FunctionRn f, double v0, double h, double left, double right);

};

#endif // RUNGE_KUTTA_H