#include "FunctionRn.h"
#include <stdlib.h>
#include <cmath>

#define NULL_FUNCTION "EXCEPTION: NULL FUNCTION CALLED"

/* ==========================================================
                         Constructors
========================================================== */
FunctionRn::FunctionRn( double (*functionRn) (std::vector<double>) )
: _functionRn(functionRn)
{}

FunctionRn::FunctionRn()
: _functionRn(NULL)
{}

/* ==========================================================
                             Set
========================================================== */
void FunctionRn::setFunction(double (*functionRn)( std::vector<double> ))
{
  this->_functionRn = functionRn;
}

/* ==========================================================
                             Run
========================================================== */
// Runs function using 'x' as the argument and returns f(x)
double FunctionRn::run(std::vector<double> params)
{
  if (_functionRn != NULL)
    { return _functionRn(params); }
  throw NULL_FUNCTION;
}
