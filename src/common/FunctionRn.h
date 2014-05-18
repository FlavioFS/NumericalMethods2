#ifndef FUNCTIONRN_H
#define FUNCTIONRN_H

#include <vector>

class FunctionRn
{
    public:

		/* ==========================================================
                                 Constructors
        ========================================================== */
    	FunctionRn( double(*functionRn)(std::vector<double>) );
        FunctionRn();

        /* ==========================================================
                                     Set
        ========================================================== */
        void setFunction( double(*functionRn)(std::vector<double>) );

        /* ==========================================================
                                      Run
        ========================================================== */
        // Runs function using 'x' as the argument and returns f(x)
        double run(std::vector<double>);


    private:
        // Multiple variable function
        double (*_functionRn) (std::vector<double>);
};

#endif // FUNCTIONRN_H
