#ifndef FUNCTION_H
#define FUNCTION_H

#include "IFunction.h"

/*  Object: Function
 *  Implements a function with domain and codomain as the set of real numbers
 */
class Function : public IFunction
{
    public:

		// Constructor
    	Function();

		// Destructor
		~Function();

        // Runs function using 'x' as the argument and returns f(x)
        double run(double x);

        void setFunction(double (*function)(double));

    private:

    	// Ponteiro que armazena a função
    	double (*function)(double);
};




#endif // FUNCTION_H
