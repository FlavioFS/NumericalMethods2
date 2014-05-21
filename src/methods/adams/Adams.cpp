#include "Adams.h"
#include <cmath>
#include <vector>
#include <iostream>

// [1] - Third Order Adams
std::vector<point> Adams::thirdOrder (FunctionRn f, double v0, double h, double left, double right)
{
	// Calculating initial points
	double ti = left + h;
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

	ti += h;
	while(ti < right) {

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
	/* TO DO */

	// Calculating initial points
	double ti = left + h;
	std::vector<point> results = RungeKutta::fourthOrder(f, v0, h, left, ti);

	if (ti >= right)
		return results;
	
	std::vector<double> params;		// Parameters vector used to calculate f(vi, ti)
	std::vector<double> params_1;	// Parameters vector used to calculate f(vi-1, ti - h)
	std::vector<double> params_2;	// Parameters vector used to calculate f(vi-2, ti - 2h)
	std::vector<double> params_3;	// Parameters vector used to calculate f(vi-3, ti - 3h)
	std::vector<double> params_;	// Parameters vector used to calculate f(vi_, ti + 1)

	unsigned int
		i = 2;

	double
		vi = results[i].y,
		vi_ = 0;

	ti += h;
	while(ti < right) {

		params.clear();
		params.push_back(results[i].x);
		params.push_back(results[i].y);

		params_1.clear();
		params_1.push_back(results[i-1].x);
		params_1.push_back(results[i-1].y);

		params_2.clear();
		params_2.push_back(results[i-2].x);
		params_2.push_back(results[i-2].y);

		params_3.clear();
		params_3.push_back(results[i-3].x);
		params_3.push_back(results[i-3].y);

		// Estimating vi+1
		vi_ = vi + (h/24) * (55*f.run(params) - 59*f.run(params_1) + 37*f.run(params_2) - 9*f.run(params_3)); //Talves esteja errado aqui OLHA ESSA LINHA

		// ti + 1
		ti = ti + h;

		params_.clear();
		params_.push_back(vi_);
		params_.push_back(ti);

		// Calculating vi+1
		vi = vi + (h/24) * (9*f.run(params_) + 19*f.run(params) - 5*f.run(params_1) + f.run(params_2));

		point latest_result = {ti, vi};
		results.push_back(latest_result);
	}

    return results;
}