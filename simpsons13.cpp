#include "Simpsons13.h"

#include <cstdio>

/* ==========================================================
                         Constructors
========================================================== */
Simpsons13::Simpsons13(std::vector<function> f)
    : f(f)
{}

/* ==========================================================
                             Sets
========================================================== */
void Simpsons13::setFunction(std::vector<function> f)
{
    (this->f).clear();
    this->f = f;
}

// Private
void Simpsons13::setArea(double area)
{
    if (area >= 0)
        this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double Simpsons13::getArea() { return area; }



/* ==========================================================
                             Run
========================================================== */

/*Alpha version, please do not use a sample with the
* wrong number of points.
*/

bool Simpsons13::run()
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
        int j = 1;
        for (; i != last; i++) {

            /*Somewhere around here this will use the trapezoidal method to solve
            * intervals with the wrong number of points.
            */
            if((j%2)!=0) {
                Sn += 4*(i->y);
            }
            else {
                Sn += 2*(i->y);
            }
            j++;
        }
    }
    Sn += (first->y + last->y);

    double h = (last->x - first->x)/(f.size() - 1);

    Sn = Sn*h*1/3;

    setArea(Sn);

    return true;
}

