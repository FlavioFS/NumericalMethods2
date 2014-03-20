#include "newtonCotes.h"
#include <cmath>
#include <cstdio>

/* ==========================================================
                         Constructors
========================================================== */
NewtonCotes::NewtonCotes(std::vector<point> P, std::vector<unsigned int> header)
    : P(P)
{
    switch (header[2])
    {
        case 1:
            double f1 (double x) { return (1/sqrt(x)); };
            f.setFunction(f1);
        break;

        case 2:
            double f2 (double x) { return (1/sqrt(1-x*x)); };
            f.setFunction(f2);
        break;

        case 3:
            double f3 (double x) { return (2*x*x*x + 3*x*x +6*x + 1); };
            f.setFunction(f3);
        break;

        case 4:
            double f4 (double x) { return (1 - x - 4*x*x*x +2*fpow(x,5)); };
            f.setFunction(f4);
        break;

        case 5:
            double f5 (double x) { return (4/(1 + x*x)); };
            f.setFunction(f5);
        break;
    }


}

/* ==========================================================
                             Sets
========================================================== */
void NewtonCotes::setPoints(std::vector<point> P)
{
    (this->P).clear();
    this->P = P;
}

void NewtonCotes::setFunction(Function f)
{
    this->f.setFunction(f);
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
    if (P.empty())
        return false;

    /* +-------------------------------------------------------------------+ *
     * | Sn = (1/2)*(x_n - x_0)*( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) ) | *
     * |   The sequence of steps below reduce the number of mathematical   | *
     * | operations and, therefore, reduces the numerical error.           | *
     * +-------------------------------------------------------------------+ */
    double Sn = 0;
    const int n = P.size() + 1;

    std::vector<point>::iterator first = P.begin();
    std::vector<point>::iterator last = P.end();
    last--;

    if (P.size() > 2)
    {
        // SUM_{1,n-1} f(x_k)
        std::vector<point>::iterator i = first;
        i++;
        for (; i != last; i++) {
            Sn += i->y;
        }

        // 2*SUM_{1,n-1} f(x_k)
        Sn *= 2;
    }

    // ( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) )
    Sn += (first->y + last->y);

    // h = (x_n - x_0)/2n
    double h = (last->x - first->x)/(2*(P.size() - 1));

    // (1/2n)*(x_n - x_0)*( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) )
    Sn *= h;

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
