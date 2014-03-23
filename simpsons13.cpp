#include "simpsons13.h"

#include <cstdio>

/* ==========================================================
                         Constructors
========================================================== */
Simpsons13::Simpsons13(std::vector<point> P)
    : P(P)
{
    // Calculating H
    std::vector<point>::iterator first = P.begin();
    std::vector<point>::iterator last = P.end();
    setH((last->x - first->x)/(P.size() - 1));
}

Simpsons13::Simpsons13()
{
}

/* ==========================================================
                             Sets
========================================================== */
void Simpsons13::setPoints(std::vector<point> P)
{
    (this->P).clear();
    this->P = P;
}

// Private
void Simpsons13::setArea(double area)
{   this->area = area; }

void Simpsons13::setH(double h)
{   this->h = h; }

/* ==========================================================
                             Gets
========================================================== */
double Simpsons13::getArea() { return area; }

double Simpsons13::getH() { return h; }

/* ==========================================================
                             Run
========================================================== */

/* +----------------------------------------------------+ *
 * | Alpha version, please do not use a sample with the | *
 * |  wrong number of points.                           | *
 * +----------------------------------------------------+ */

bool Simpsons13::run()
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

    //double h = (last->x - first->x)/(P.size() - 1);

    Sn = Sn*getH()*1/3;

    setArea(Sn);

    return true;
}

