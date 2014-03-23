#include "trapezoidal.h"

#include <cstdio>

/* ==========================================================
                         Constructors
========================================================== */
Trapezoidal::Trapezoidal(std::vector<point> P)
    : P(P)
{
    // Calculating H
    std::vector<point>::iterator first = P.begin();
    std::vector<point>::iterator last = P.end();
    setH((last->x - first->x)/(P.size() - 1));
}

Trapezoidal::Trapezoidal()
{

}
/* ==========================================================
                             Sets
========================================================== */
void Trapezoidal::setPoints(std::vector<point> P)
{
    (this->P).clear();
    this->P = P;
}

// Private
void Trapezoidal::setArea(double area)
{
    this->area = area;
}

void Trapezoidal::setH(double h)
{
    this->h = h;
}

/* ==========================================================
                             Gets
========================================================== */
double Trapezoidal::getArea() { return area; }

double Trapezoidal::getH() { return h; }
/* ==========================================================
                             Run
========================================================== */
bool Trapezoidal::run()
{
    if (P.empty())
        return false;

    /* +-------------------------------------------------------------------+ *
     * | Sn = (1/2)*(x_n - x_0)*( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) ) | *
     * |   The sequence of steps below reduce the number of mathematical   | *
     * | operations and, therefore, reduces the numerical error.           | *
     * +-------------------------------------------------------------------+ */
    double Sn = 0;

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

    // (1/2n)*(x_n - x_0)*( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) )
    setArea((Sn * getH()) / 2);

    return true;
}
