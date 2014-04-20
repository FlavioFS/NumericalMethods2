#include "Function.h"
#include <stdlib.h>
#include <cmath>

#define NULL_FUNCTION "EXCEPTION: NULL FUNCTION CALLED"

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
// Choose a default function
// Index goes from 1 to 5
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

// Choose a function in the list
// Index goes from 1 to n
void Function::pickFunction(unsigned int option)
{  
  if (option < _functionList.size())
    { setFunction(_functionList[option-1]); }
}

void Function::setFunction(double (*function)(double))
{
  this->function = function;
}

void Function::pushBackFunction(double (*function)(double))
{
  _functionList.push_back(function);
}
/* ==========================================================
                             Run
========================================================== */
// Runs function using 'x' as the argument and returns f(x)
double Function::run(double x)
{
  if (function != NULL)
    { return function(x); }
  throw NULL_FUNCTION;
}

/* ==========================================================
                      Default Functions
========================================================== */
/* Deprecated - Use pushBackFunction + setFunction this way:
double f1(double x) { return (1/sqrt(x)); }
double f2(double x) { return (1/sqrt(1-x*x)); }
double f3(double x) { return (2*x*x*x + 3*x*x +6*x + 1); }
double f4(double x) { return (1 - x - 4*x*x*x +2*powf(x,5)); }
double f5(double x) { return (4/(1 + x*x)); }

Function f;
f.pushBackFunction(f1);
f.pushBackFunction(f2);
f.pushBackFunction(f3);
f.pushBackFunction(f4);
f.pushBackFunction(f5);

// Choose f3
f.pickFunction(3);
cout << f.run(1.333) << endl;
*/

// ~~~~ First list ~~~~
double Function::f1(double x) { return (1/sqrt(x)); }
double Function::f2(double x) { return (1/sqrt(1-x*x)); }
double Function::f3(double x) { return (2*x*x*x + 3*x*x +6*x + 1); }
double Function::f4(double x) { return (1 - x - 4*x*x*x +2*powf(x,5)); }
double Function::f5(double x) { return (4/(1 + x*x)); }

/* ~~~~ Second list ~~~~
double Function::f1(double x) { return ( - 0.1*x*x*x*x - 0.15*x*x*x - (x*x/2) + 1.2); }
double Function::f2(double x) { return ( 2*x*x*x*x - 6*x*x*x - 12*x - 8); }
double Function::f3(double x) { return ( 2*x*x*x + 3*x*x +6*x + 1); }
double Function::f4(double x) { return ( 1 - x - 4*x*x*x +2*powf(x,5)); }
*/
