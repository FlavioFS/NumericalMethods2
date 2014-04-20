#ifndef FUNCTION_H
#define FUNCTION_H

#include "../includes/IFunction.h"
#include <vector>

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
        void pushBackFunction(double (*function)(double));
        void pickFunction(unsigned int option);


        /* ==========================================================
                                      Run
        ========================================================== */
        // Runs function using 'x' as the argument and returns f(x)
        double run(double x);


    private:
    	// Pointer that stores the function
    	double (*function)(double);

        // Dynamic list of functions
        std::vector< double (*)(double) > _functionList;

        // Default Functions
        // Deprecated - Use pushBackFunction + setFunction
        static double f1 (double x);
        static double f2 (double x);
        static double f3 (double x);
        static double f4 (double x);
        static double f5 (double x);
};

#endif // FUNCTION_H
