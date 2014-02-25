#include "IMethod.h"
#include <vector>

class Simpsons38 : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Simpsons38(std::vector<function> f);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setFunction(std::vector<function> f);

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

    std::vector<function> f;   // Function (Discrete sample)
    double area;               // Calculated integral
};
