#ifndef FUNCTION_H
#define FUNCTION_H

#import "IFunction.h"

class Function : public IFunction
{
    public:

		/* ==========================================================
                                 Constructors
        ========================================================== */
    	Function();
    	Function(double (*function)(double));

        /* ==========================================================
                                     Set
        ========================================================== */
        void setFunction(double (*function)(double));


        /* ==========================================================
                                      Run
        ========================================================== */
        // Runs function using 'x' as the argument and returns f(x)
        double run(double x);


    private:

    	// Pointer that stores the function
    	double (*function)(double);
};

#endif // FUNCTION_H
