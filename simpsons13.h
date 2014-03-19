#include "IMethod.h"
#include <vector>

class Simpsons13 : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Simpsons13(std::vector<point> f);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setFunction(std::vector<point> f);

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

    std::vector<point> f;   // Function (Discrete sample)
    double area;               // Calculated integral
};
