#include "../IMethod.h"
#include <vector>
#include "sampleMultipleIntegral.h"

class MultipleIntegral : public IMethod
{
public:

    
    /* ==========================================================
                             Constructors
    ========================================================== */
    MultipleIntegral(double **M);

    MultipleIntegral(double **M, double hx, double hy);
    /* ==========================================================
                                 Sets
    ========================================================== */
    void setPoints(double **M);

    void setHx(double hx);

    void setHy(double hy);

    /* ==========================================================
                                 Gets
    ========================================================== */
    double getArea();

    double getHx();

    double getHy();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:
    // Private set
    void setArea(double area);

    double **M;   // Function (Discrete sample)

    double area;            // Calculated integral

    double hx, hy;
};
