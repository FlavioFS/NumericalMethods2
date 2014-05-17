#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

class FunctionRn
{
    public:

		/* ==========================================================
                                 Constructors
        ========================================================== */
    	FunctionRn(double (*functionRn)( std::vector<double> ));

        /* ==========================================================
                                     Set
        ========================================================== */
        void setFunction( double (*functionRn)(std::vector<double>) );

        /* ==========================================================
                                      Run
        ========================================================== */
        // Runs function using 'x' as the argument and returns f(x)
        double run(std::vector<double>);


    private:
        // Multiple variable function
        double (*_functionRn) (std::vector<double>);
};

#endif // FUNCTION_H
