#include "RungeKutta.h"
#include <cmath>
#include <iostream>
#include <iostream>

using namespace std;

// [1] - Second Order Runge Kutta
double RungeKutta::secondOrder (FunctionRn f, double v0, double h, double left, double right)
{
    
	double vi = v0, 
		  _vi = 0,
		   ti = left;

	// Parameters vector used to calculate f(vi, ti)
	vector<double> params;
	// Parameters vector used to calculate f(vi_, ti + 1)
	vector<double> params_;

	while(ti <= right) {

		params.clear();
		params.push_back(vi);
		params.push_back(ti);

		// vi_ + 1 = vi + h(f(vi, ti))
		_vi = vi + h*f.run(params);		

		// ti + 1
		ti = ti + h;

		params_.clear();
		params_.push_back(_vi);
		params_.push_back(ti);

		// vi+1 = vi + h/2[f(vi, ti) + f(vi_ + 1, ti + 1)]
		vi = vi + (h/2)*( f.run(params) + f.run(params_));
	}

    return vi;
}

