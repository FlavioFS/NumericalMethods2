#include "../../includes/IMethod.h"
#include "../../common/Function.h"
#include <vector>

class GaussianQuadrature : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    GaussianQuadrature(Function f, int n, double left, double right);

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

    //Xi's
    double x [5];

    //Ti's
    double t [5];

    //Ai's
    double A [5];

    void setArea(double area);

    Function f;         // Continuous function
    unsigned int n;     // Interval subdivision amount
    double left, right; // Interval of integration
    double area;        // Calculated integral
};
