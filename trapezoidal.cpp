#include "Trapezoidal.h"

/* ==========================================================
                         Constructors
========================================================== */
Trapezoidal::Trapezoidal(std::vector<function> f)
    : f(f)
{}

/* ==========================================================
                             Sets
========================================================== */
void Trapezoidal::setFunction(std::vector<function> f)
{
    (this->f).clear();
    this->f = f;
}

// Private
void Trapezoidal::setArea(double area)
{
    if (area >= 0)
        this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double Trapezoidal::getArea() { return area; }

/* ==========================================================
                             Run
========================================================== */
bool Trapezoidal::run()
{
    if (f.empty())
        return false;

    /* Sn = (1/2)*(x_n - x_0)*( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) )
     *   The sequence of steps below reduce the number of mathematical
     * operations and, therefore, reduces the numerical error.
    */
    double Sn = 0;

    std::vector<function>::iterator first = f.begin();
    std::vector<function>::iterator last = f.end();
    last--;

    if (f.size() > 2)
    {
        // SUM_{1,n-1} f(x_k)
        std::vector<function>::iterator i = first;
        i++;
        for (; i != last; i++)
        {
            Sn += i->y;
        }

        Sn *= 2;                  // 2*SUM_{1,n-1} f(x_k)
    }
    Sn += (first->y + last->y);   // ( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) )
    Sn *= (last->x - first->x)/2; // (1/2)*(x_n - x_0)*( f(x_0) + f(x_n) + 2*SUM_{1,n-1} f(x_k) )

    setArea(Sn);

    return true;
}
