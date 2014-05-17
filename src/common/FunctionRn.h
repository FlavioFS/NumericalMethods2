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
    	Function(double (*functionRn)( std::vector<double> ));

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
        double (*) (std::vector<double>) _functionRn;
};

#endif // FUNCTION_H
