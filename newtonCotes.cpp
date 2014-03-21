#include "newtonCotes.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
NewtonCotes::NewtonCotes(Function f, int n, double left, double right)
    : f(f), n(n), left(left), right(right)
{}

/* ==========================================================
                             Sets
========================================================== */
void NewtonCotes::setFunction(Function f)
{
    this->f = f;
}

void NewtonCotes::setN(const unsigned int n)
{
    this->n = n;
}

// Private
void NewtonCotes::setArea(double area)
{
    this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double NewtonCotes::getArea() { return area; }

/* ==========================================================
                             Run
========================================================== */
bool NewtonCotes::run()
{
    /* +-------------------------------------------------------------------+ *
     * | Sn = a*h*SUM_{0,n+2} (c_i*f(a + i*h))                             | *
     * |   The sequence of steps below reduce the number of mathematical   | *
     * | operations and, therefore, reduces the numerical error.           | *
     * +-------------------------------------------------------------------+ */
    double Sn = 0;
    double h = (right - left)/(n+2);

    // Sn = SUM_{0,n+2} (c_i*f(a + i*h))
    for (unsigned int i = 1; i < n+2; i++)
    {
        Sn += coefficientsMap(n, i)*f.run(left+i*h);
    }

    Sn *= h;    // Sn = h*SUM_{0,n+2} (c_i*f(a + i*h))
    Sn *= alpha[n]; // Sn = a*h*SUM_{0,n+2} (c_i*f(a + i*h))

    setArea(Sn);

    return true;
}

/* ==========================================================
                        Coeficients Map
========================================================== */
// Coeficients in Newton-Cotes formula
int NewtonCotes::coefficientsMap(int n, int position)
{
    return coefficients[n-1][position];
}
