#include "../../../includes/IMethod.h"
#include "../../../common/Matrix.h"

class Qr : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Qr(Matrix A, int order, double e);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setMatrix(Matrix A);
    void setOrder(const unsigned int order);
    void setE(const double e);

    /* ==========================================================
                                 Gets
    ========================================================== */
    Matrix getA();

    Matrix getP();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();


protected:

    Matrix A;             // The Matrix
    Matrix P;             // Matriz de autovetores
    unsigned int order;  // Matrix order
    double e;           // Tolerance
};
