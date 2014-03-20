#include "simpsons38.h"

#include <cstdio>

/* ==========================================================
                         Constructors
========================================================== */
Simpsons38::Simpsons38(std::vector<point> P)
    : P(P)
{}

/* ==========================================================
                             Sets
========================================================== */
void Simpsons38::setPoints(std::vector<point> P)
{
    (this->P).clear();
    this->P = P;
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

/* +----------------------------------------------------+ *
 * | Alpha version, please do not use a sample with the | *
 * |  wrong number of points.                           | *
 * +----------------------------------------------------+ */

bool Simpsons38::run()
{
    if (P.empty())
        return false;


    double Sn = 0;

    std::vector<point>::iterator first = P.begin();
    std::vector<point>::iterator last = P.end();
    last--;

    if (P.size() > 2)
    {
        std::vector<point>::iterator i = first;
        i++;
        int j = 1;
        for (; i != last; i++) {

            /* +---------------------------------------------------------------------+ *
             * | Somewhere around here this will use the trapezoidal method to solve | *
             * |  intervals with the wrong number of points.                         | *
             * +---------------------------------------------------------------------+ */
            if((j%3)!=0) {
                Sn += 3*(i->y);
            }
            else {
                Sn += 2*(i->y);
            }
            j++;
        }
    }
    Sn += (first->y + last->y);

    double h = (last->x - first->x)/(P.size() - 1);

    Sn = Sn*h*3/8;

    setArea(Sn);

    return true;
}

