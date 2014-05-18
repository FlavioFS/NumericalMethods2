#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

#include <vector>
#include "../../../src/common/FunctionRn.h"

class RungeKutta
{
    public:
    	   
        // [1] - Second Order Runge Kutta
        static double secondOrder (FunctionRn f, double v0, double h, double left, double right);

};

#endif // RUNGE_KUTTA_H
