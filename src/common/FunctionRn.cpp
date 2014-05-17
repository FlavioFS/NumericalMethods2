#include "Function.h"
#include <stdlib.h>
#include <cmath>

#define NULL_FUNCTION "EXCEPTION: NULL FUNCTION CALLED"

/* ==========================================================
                         Constructors
========================================================== */
Function::Function( double (*functionRn) (std::vector<double>) )
: functionRn(functionRn)
{}

/* ==========================================================
                             Set
========================================================== */
void Function::setFunction(double (*functionRn)( std::vector<double> ))
{
  this->functionRn = functionRn;
}

/* ==========================================================
                             Run
========================================================== */
// Runs function using 'x' as the argument and returns f(x)
double Function::run(std::vector<double> params)
{
  if (function != NULL)
    { return function(params); }
  throw NULL_FUNCTION;
}