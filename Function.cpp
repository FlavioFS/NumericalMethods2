
#include <stdlib.h>
#include "Function.h"


// Constructor
Function::Function()
{
	function = NULL;
}

// Destructor
Function::~Function()
{

}

// Runs function using 'x' as the argument and returns f(x)
double Function::run(double x)
{
    return function(x);
}

void Function::setFunction(double (*function)(double))
{
	this->function = function;
}
