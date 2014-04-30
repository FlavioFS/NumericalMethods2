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
    void setMatrix(Matrix A);
    void setOrder(const unsigned int order);
    void setE(const double e);
    void setU(const double u);

    /* ==========================================================
                                 Gets
    ========================================================== */
    double getEigenvalue() const;
    const Matrix getEigenvector() const;

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:

    void setEigenvalue(double value);

    Matrix A;           // The Matrix
    Matrix qk;          // Eigenvector
    unsigned int order; // Matrix order
    double e;           // Tolerance
    double u;           // u
    double eigenvalue;
};

#endif // SHIFTED_POWER_H
