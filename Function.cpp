#include <stdlib.h>
#include "Function.h"

/* ==========================================================
                         Constructors
========================================================== */
Function::Function()
: function(NULL)
{}

Function::Function(double (*function)(double))
: function(function)
{}

/* ==========================================================
                             Set
========================================================== */
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


