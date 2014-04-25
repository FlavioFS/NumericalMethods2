#include "../../../includes/IMethod.h"
#include "../../../common/Matrix.h"
#include <vector>
#include "lu.h"

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
    void setMartrix(Matrix A);
    void setOrder(const unsigned int order);
    void setE(const double e);

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

    Matrix A;             // The Matrix
    unsigned int order;  // Matrix order
    double e;           // Tolerance
    double area;       // Calculated integral
};
