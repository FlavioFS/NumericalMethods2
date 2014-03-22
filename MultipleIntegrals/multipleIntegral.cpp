#include <cstdio>
#include "multipleIntegral.h"
#include "../simpsons13.h"
#include "../trapezoidal.h"


/* ==========================================================
                         Constructors
========================================================== */
MultipleIntegral::MultipleIntegral(double **M)
    : M(M)
{}

MultipleIntegral::MultipleIntegral(double **M, double hx, double hy)
{
    this->M = M;
    this->hx = hx;
    this->hy = hy;
}

/* ==========================================================
                             Sets
========================================================== */
void MultipleIntegral::setPoints(double **M)
{
    
    this->M = M;
}

void MultipleIntegral::setHx(double hx)
{ this->hx = hx; }

void MultipleIntegral::setHy(double hy)
{ this->hy = hy; }

// Private
void MultipleIntegral::setArea(double area)
{
    this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double MultipleIntegral::getArea() { return area; }

double MultipleIntegral::getHx()
{ return this->hx; }

double MultipleIntegral::getHy()
{ return this->hy; }

/* ==========================================================
                             Run
========================================================== */

bool MultipleIntegral::run()
{
    

    return true;
}

