#include "RungeKutta.h"
#include <cmath>
#include <iostream>
#include <iostream>

using namespace std;

// [1] - Second Order Runge Kutta
std::vector<point> RungeKutta::secondOrder (FunctionRn f, double v0, double h, double left, double right)
{
    
	double vi = v0, 
		  _vi = 0,
		   ti = left;

	// List of 'point' that will be returned
	std::vector<point> results;
	results.clear();

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

		point latest_result = {ti, vi};
		results.push_back(latest_result);
	}

    return results;
}

// [2] - Third Order Runge Kutta
std::vector<point> RungeKutta::thirdOrder (FunctionRn f, double v0, double h, double left, double right)
{
    
	double vi = v0, 
		  _vi_middle = 0,
		  _vi = 0,
		   ti = left;

	// List of 'point' that will be returned
	std::vector<point> results;
	results.clear();

	// Parameters vector used to calculate f(vi, ti)
	vector<double> params;

	// Parameters vector used to calculate f(vi + 1/2, ti + 1/2)
	vector<double> params_middle;

	// Parameters vector used to calculate f(vi + 1, ti + 1)
	vector<double> params_;

	while(ti <= right) {

		params.clear();
		params.push_back(vi);
		params.push_back(ti);

		// _vi + 1/2 = vi + h/2(f(vi, ti))
		_vi_middle = vi + (h/2)*f.run(params);		

		// ti + 1/2
		ti = ti + (h/2);

		params_middle.clear();
		params_middle.push_back(_vi_middle);
		params_middle.push_back(ti);

		// _vi + 1 = vi + h[-f(vi, ti) + 2f(_vi + 1/2, ti + 1/2)]
		_vi = vi + h*( -f.run(params) + 2*f.run(params_middle));

		// ti + 1
		ti = ti + (h/2);

		params_.clear();
		params_.push_back(_vi);
		params_.push_back(ti);

		// vi + 1 = vi + h/6(f(vi, ti) + 4f(_vi + 1/2, ti + 1/2) + f(_vi + 1, ti + 1))
		vi = vi + (h/6)*((f.run(params)) + 4*f.run(params_middle) + f.run(params_));

		point latest_result = {ti, vi};
		results.push_back(latest_result);
	}

    return results;
}

