#ifndef MULTIPLE_INTEGRAL_H
#define MULTIPLE_INTEGRAL_H

#include <vector>

#include "../IMethod.h"

#include "sampleMultipleIntegral.h"

class MultipleIntegral : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    MultipleIntegral(double **M);

    MultipleIntegral(double **M, double hx, double hy, unsigned int mx, unsigned int my);
    /* ==========================================================
                                 Sets
    ========================================================== */
    void setPoints(double **M);

    void setHx(double hx);

    void setHy(double hy);

    void setMx(unsigned int mx);

    void setMy(unsigned int my);
    /* ==========================================================
                                 Gets
    ========================================================== */
    double getArea();

    double getHx();

    double getHy();

    unsigned int getMx();

    unsigned int getMy();
    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:
    // Private set
    void setArea(double area);

    double **M;          // Discrete sample

    double area;         // Calculated integral

    double hx, hy;       // Used to calculate h

    unsigned int mx, my; // x and y dimensions
};

#endif // MULTIPLE_INTEGRAL_H
