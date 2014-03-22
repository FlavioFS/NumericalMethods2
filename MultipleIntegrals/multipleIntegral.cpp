#include <iostream>

#include "multipleIntegral.h"

#include "../simpsons13.h"
#include "../trapezoidal.h"

using namespace std;
/* ==========================================================
                         Constructors
========================================================== */
MultipleIntegral::MultipleIntegral(double **M)
    : M(M)
{}

MultipleIntegral::MultipleIntegral(double **M, double hx, double hy, unsigned int mx, unsigned int my)
{
    this->M = M;
    this->hx = hx;
    this->hy = hy;
    this->mx = mx;
    this->my = my;
}

/* ==========================================================
                             Sets
========================================================== */
void MultipleIntegral::setPoints(double **M)
{   this->M = M; }

void MultipleIntegral::setHx(double hx)
{ this->hx = hx; }

void MultipleIntegral::setHy(double hy)
{ this->hy = hy; }

// Private
void MultipleIntegral::setArea(double area)
{ this->area = area; }

void MultipleIntegral::setMx(unsigned int mx)
{ this->mx = mx; }

void MultipleIntegral::setMy(unsigned int my)
{ this->mx = mx; }

/* ==========================================================
                             Gets
========================================================== */
double MultipleIntegral::getArea() { return area; }

double MultipleIntegral::getHx()
{ return this->hx; }

double MultipleIntegral::getHy()
{ return this->hy; }

unsigned int MultipleIntegral::getMx()
{ return this->mx; }

 unsigned int MultipleIntegral::getMy()
{ return this->my; }

/* ==========================================================
                             Run
========================================================== */

bool MultipleIntegral::run()
{
   
    std::vector<point> xAxisValues;
    std::vector<point> yAxisValues;

    for(int i = getMy()+1; i <= 0; i--)
    {
        xAxisValues.clear();
        
        // constructs the vector of points
        for (int j = 0; j < getMx()+1; ++j)
        {   
            point x;

            x.y = M[i][j];
            xAxisValues.push_back(x);
        }

        Simpsons13 simpsonX (xAxisValues);
        simpsonX.setH(getHx());
        simpsonX.run();

        point y;
        y.y = simpsonX.getArea();
        yAxisValues.push_back(y);
    }
    
    Simpsons13 simpsonY(yAxisValues);
    simpsonY.setH(getHy());
    simpsonY.run();  

    cout << simpsonY.getArea();

    return true;
}

