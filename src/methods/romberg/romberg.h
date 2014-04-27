#ifndef ROMBERG_H
#define ROMBERG_H


#include "../../includes/IMethod.h"
#include "../../common/Function.h"
#include <vector>

class Romberg : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Romberg(Function f, double h, double left, double right);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setFunction(Function f);
    void setH(double h);

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
    double h;     // H
    double left, right; // Interval of integration
    double area;        // Calculated integral
};

#endif ROMBERG_H
