#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#include "IMethod.h"
#include <vector>

class Trapezoidal : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Trapezoidal(std::vector<point> f);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setFunction(std::vector<point> f);

    /* ==========================================================
                                 Gets
    ========================================================== */
    double getArea();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:
    // Private set
    void setArea(double area);

    std::vector<point> f;   // Function (Discrete sample)
    double area;            // Calculated integral
};

#endif // TRAPEZOIDAL_H
