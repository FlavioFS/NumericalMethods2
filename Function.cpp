#include "Function.h"
#include <stdlib.h>
#include <cmath>

/* ==========================================================
                         Constructors
========================================================== */
Function::Function()
: function(NULL)
{}

Function::Function(const int n)
{
    setFunction(n);
}

Function::Function(double (*function)(double))
: function(function)
{}

/* ==========================================================
                             Set
========================================================== */
void Function::setFunction(unsigned int option)
{
    if (option == 1)
        { setFunction(this->f1); }

    else if (option == 2)
        { setFunction(this->f2); }

    else if (option == 3)
        { setFunction(this->f3); }

    else if (option == 4)
        { setFunction(this->f4); }

    else
        { setFunction(this->f5); }
}

void Function::setFunction(double (*function)(double))
{
	this->function = function;
}

/* ==========================================================
                             Run
========================================================== */
// Runs function using 'x' as the argument and returns f(x)
double Function::run(double x)
{
    return function(x);
}

/* ==========================================================
                      Default Functions
========================================================== */
double Function::f1(double x) { return (1/sqrt(x)); }
double Function::f2(double x) { return (1/sqrt(1-x*x)); }
double Function::f3(double x) { return (2*x*x*x + 3*x*x +6*x + 1); }
double Function::f4(double x) { return (1 - x - 4*x*x*x +2*powf(x,5)); }
double Function::f5(double x) { return (4/(1 + x*x)); }
