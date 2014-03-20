#ifndef NEWTONCOTES_H
#define NEWTONCOTES_H

#include "IMethod.h"
#include "function.h"
#include <vector>

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
    NewtonCotes(std::vector<point> P, std::vector<unsigned int> header);

    /* ==========================================================
                                 Sets
    ========================================================== */
    void setPoints(std::vector<point> P);
    void setFunction(Function f);

    /* ==========================================================
                                 Gets
    ========================================================== */
    double getArea();

    /* ==========================================================
                                 Run
    ========================================================== */
    bool run();

private:

    /* +----------------------------------------------------------+ *
     * | Coefficients when n belongs to [1, 4].                   | *
     * | The first index stands for the n value (point qnt. + 1). | *
     * | The second index stands for the coefficient position.    | *
     * +----------------------------------------------------------+ */
    const static short int
        coeficients[4][7] = { { 0,  1,   1,  0,  0,  0,  0},
                              { 0,  2,  -1,  2,  0,  0,  0},
                              { 0, 11,   1,  1,  11, 0,  0},
                              { 0, 11, -14, 26, -14, 11, 0} };

    // Alpha values. The index stands for the n value.
    const static double alpha[4] = {3/2, 4/3, 5/24, 6/20};

    // Index map
    int coeficientsMap(int n, int index);

    // Private set
    void setArea(double area);

    Function f;             // Continuous function
    std::vector<point> P;   // Sample points (discrete function)
    double area;            // Calculated integral
};

#endif // NEWTONCOTES_H
