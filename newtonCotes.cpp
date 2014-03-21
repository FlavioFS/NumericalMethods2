#include "newtonCotes.h"
#include <cmath>
#include <cstdio>

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
    if (area >= 0)
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
    double h = (right - left)/n;

    // Sn = SUM_{0,n+2} (c_i*f(a + i*h))
    for (int i = 0; i < n+2; i++)
    {
        Sn += coeficientsMap(n, i)*f.run(left+i*h);
    }

    Sn *= h;    // Sn = h*SUM_{0,n+2} (c_i*f(a + i*h))
    Sn *= left; // Sn = a*h*SUM_{0,n+2} (c_i*f(a + i*h))

    setArea(Sn);

    return true;
}

/* ==========================================================
                        Coeficients Map
========================================================== */
// Coeficients in Newton-Cotes formula
int NewtonCotes::coeficientsMap(int n, int position)
{
    return coeficients[n][position];
}
