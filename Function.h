#ifndef FUNCTION_H
#define FUNCTION_H

#include "IFunction.h"

class Function : public IFunction
{
    public:

		/* ==========================================================
                                 Constructors
        ========================================================== */
    	Function();
    	Function(const int n);
    	Function(double (*function)(double));

        /* ==========================================================
                                     Set
        ========================================================== */
        void setFunction(unsigned int option);
        void setFunction(double (*function)(double));


        /* ==========================================================
                                      Run
        ========================================================== */
        // Runs function using 'x' as the argument and returns f(x)
        double run(double x);


    private:

    	// Pointer that stores the function
    	double (*function)(double);

        // Default Functions
        static double f1 (double x);
        static double f2 (double x);
        static double f3 (double x);
        static double f4 (double x);
        static double f5 (double x);
};

#endif // FUNCTION_H
