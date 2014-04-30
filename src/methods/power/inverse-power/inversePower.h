#ifndef INVERSE_POWER_H
#define INVERSE_POWER_H

#include "../../../includes/IMethod.h"
#include "../../../common/Matrix.h"
#include "../../../common/lu.h"
#include <vector>

class InversePower : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    InversePower(Matrix A, int order, double e);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setMatrix(Matrix A);
    void setOrder(const unsigned int order);
    void setE(const double e);

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
    double eigenvalue;
};

#endif // INVERSE_POWER_H
