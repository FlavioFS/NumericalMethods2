#include "../../../includes/IMethod.h"
#include "../../../common/Matrix.h"
#include "../simple/qr.h"

class QrHouseholder : public Qr
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    QrHouseholder(Matrix A, int order, double e);

    /* ==========================================================
                                 Gets
    ========================================================== */
    Matrix getHouseholded();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:
    Matrix householded;
};
