#ifndef NEWTONCOTES_H
#define NEWTONCOTES_H

#include "../../includes/IMethod.h"
#include "../../common/Function.h"
#include <vector>

/* +----------------------------------------------------------+ *
 * | Coefficients when n belongs to [1, 4].                   | *
 * | The first index stands for the n value (point qnt. + 1). | *
 * | The second index stands for the coefficient position.    | *
 * +----------------------------------------------------------+ */
const int coefficients[4][7] = {
        {0,  1,   1,  0,  0,   0, 0},
        {0,  2,  -1,  2,  0,   0, 0},
        {0, 11,   1,  1,  11,  0, 0},
        {0, 11, -14, 26, -14, 11, 0}
};

// Alpha values
const double alpha[5] = {0, 3/2.0, 4/3.0, 5/24.0, 6/20.0};

/////////////////////////////////////////////////////////////
//                                                         //
// This class implements the OPEN Newton-Cotes formulae.   //
// The supported 'n' values belongs to the interval [1,4]. //
//                                                         //
/////////////////////////////////////////////////////////////
class NewtonCotes : public IMethod
{
public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    NewtonCotes(Function f, int n, double left, double right);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setFunction(Function f);
    void setN(const unsigned int n);

    /* ==========================================================
                                 Gets
    ========================================================== */
    double getArea();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:

    // Index map
    int coefficientsMap(int n, int index);

    // Private set
    void setArea(double area);

    Function f;         // Continuous function
    unsigned int n;     // Interval subdivision amount
    double left, right; // Interval of integration
    double area;        // Calculated integral
};

#endif // NEWTONCOTES_H
