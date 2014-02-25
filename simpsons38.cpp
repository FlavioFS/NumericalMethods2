#include "Simpsons38.h"

#include <cstdio>

/* ==========================================================
                         Constructors
========================================================== */
Simpsons38::Simpsons38(std::vector<function> f)
    : f(f)
{}

/* ==========================================================
                             Sets
========================================================== */
void Simpsons38::Simpsons38(std::vector<function> f)
{
    (this->f).clear();
    this->f = f;
}

// Private
void Simpsons38::setArea(double area)
{
    if (area >= 0)
        this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double Simpsons38::getArea() { return area; }



/* ==========================================================
                             Run
========================================================== */

/*Alpha version, please do not use a sample with the
* wrong number of points.
*/

bool Simpsons38::run()
{
    if (f.empty())
        return false;


    double Sn = 0;

    std::vector<function>::iterator first = f.begin();
    std::vector<function>::iterator last = f.end();
    last--;

    if (f.size() > 2)
    {
        std::vector<function>::iterator i = first;
        i++;
        for (; i != last; i++) {

            /*Somewhere around here this will use the trapezoidal method to solve
            * intervals with the wrong number os points.
            */
            if(i%3!=0) {
                Sn += 3*(i->y);
            }
            else {
                Sn += 2*(i->y);
            }
        }
    }
    Sn += (first->y + last->y);

    double h = (last->x - first->x)/(f.size() - 1);

    Sn = Sn*h*3/8;

    setArea(Sn);

    return true;
}

