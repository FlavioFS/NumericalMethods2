#ifndef ADAMS_H
#define ADAMS_H

#include <vector>
#include "../../includes/point.h"
#include "../../common/FunctionRn.h"
#include "../runge-kutta/RungeKutta.h"

class Adams
{
    public:
    	   
        // [1] - Second Order Adams
        static std::vector<point> thirdOrder (FunctionRn f, double v0, double h, double left, double right);

        // [2] - Third Order Adams
		static std::vector<point> fourthOrder (FunctionRn f, double v0, double h, double left, double right);
};

#endif // ADAMS_H