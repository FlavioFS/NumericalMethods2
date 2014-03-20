#include "IMethod.h"
#include <vector>

class Simpsons38 : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Simpsons38(std::vector<point> P);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setPoints(std::vector<point> P);

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

    std::vector<point> P;   // Function (Discrete sample)
    double area;            // Calculated integral
};
