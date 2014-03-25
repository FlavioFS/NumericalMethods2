#include "../../includes/IMethod.h"
#include "../../common/Function.h"
#include <vector>

class Romberg : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Romberg(Function f, int n, double left, double right);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setFunction(Function f);
    void setN(const unsigned int n);

    /* ==========================================================
                                 Gets
    ========================================================== */
    double getArea();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:

    void setArea(double area);

    Function f;         // Continuous function
    unsigned int n;     // H
    double left, right; // Interval of integration
    double area;        // Calculated integral
};
