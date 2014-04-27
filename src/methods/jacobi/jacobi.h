#include "../../../includes/IMethod.h"
#include "../../../common/Matrix.h"

class Jacobi : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Jacobi(Matrix A, int order, double e);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setMartrix(Matrix A);
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


private:

    Matrix A;             // The Matrix
    Matrix P;             // Matriz de autovetores
    unsigned int order;  // Matrix order
    double e;           // Tolerance
};
