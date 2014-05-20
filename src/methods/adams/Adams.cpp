#include "Adams.h"
#include <cmath>
#include <vector>
#include <iostream>

// [1] - Third Order Adams
std::vector<point> Adams::thirdOrder (FunctionRn f, double v0, double h, double left, double right)
{
	// Calculating initial points
	double ti = left + 2*h;
	std::vector<point> results = RungeKutta::thirdOrder(f, v0, h, left, ti);

	// Only 3 points in the interval
	if (ti >= right)
		return results;
	
	std::vector<double> params;		// Parameters vector used to calculate f(vi, ti)
	std::vector<double> params_1;	// Parameters vector used to calculate f(vi-1, ti - h)
	std::vector<double> params_2;	// Parameters vector used to calculate f(vi-2, ti - 2h)
	std::vector<double> params_;	// Parameters vector used to calculate f(vi_, ti + 1)

	unsigned int
		i = 2;
		
	double
		vi = results[i].y,
		vi_ = 0;

	while(ti <= right) {

		params.clear();
		params.push_back(results[i].x);
		params.push_back(results[i].y);

		params_1.clear();
		params_1.push_back(results[i-1].x);
		params_1.push_back(results[i-1].y);

		params_2.clear();
		params_2.push_back(results[i-2].x);
		params_2.push_back(results[i-2].y);

		// Estimating vi+1
		vi_ = vi + (h/12) * (23*f.run(params) - 16*f.run(params_1) + 5*f.run(params_2));

		// ti + 1
		ti = ti + h;

		params_.clear();
		params_.push_back(vi_);
		params_.push_back(ti);

		// Calculating vi+1
		vi = vi + (h/12) * (5*f.run(params_) + 8*f.run(params) - f.run(params_1));

		point latest_result = {ti, vi};
		results.push_back(latest_result);
	}

    return results;
}

// [2] - Fourth Order Adams
std::vector<point> Adams::fourthOrder (FunctionRn f, double v0, double h, double left, double right)
{
	// TODO
    /*
	double vi = v0, 
		  _vi_middle = 0,
		  _vi = 0,
		   ti = left;

	// Parameters vector used to calculate f(vi, ti)
	std::vector<double> params;
	// Parameters vector used to calculate f(vi + 1/2, ti + 1/2)
	std::vector<double> params_middle;
	// Parameters vector used to calculate f(vi + 1, ti + 1)
	std::vector<double> params_;

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
		
	}

    return _vi_middle;
    */
}