#ifndef SHIFTED_POWER_H
#define SHIFTED_POWER_H

#include "../../../includes/IMethod.h"
#include "../../../common/Matrix.h"
#include "../../../common/lu.h"
#include <vector>

class ShiftedPower : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    ShiftedPower(Matrix A, int order, double e, double u);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setMartrix(Matrix A);
    void setOrder(const unsigned int order);
    void setE(const double e);
    void setU(const double u);

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

    Matrix A;              // The Matrix
    unsigned int order;   // Matrix order
    double e;            // Tolerance
    double u;           // u
    double area;       // Calculated integral
};

#endif // SHIFTED_POWER_H
