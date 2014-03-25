#include "romberg.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
Romberg::Romberg(Function f, int n, double left, double right)
    : f(f), n(n), left(left), right(right)
{
}

/* ==========================================================
                             Sets
========================================================== */
void Romberg::setFunction(Function f)
{
    this->f = f;
}

void Romberg::setN(const unsigned int n)
{
    this->n = n;
}

// Private
void Romberg::setArea(double area)
{
    this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double Romberg::getArea() { return area; }

/* ==========================================================
                             Run
========================================================== */
bool Romberg::run()
{
    //I = 4*I(h2)/3 - I(h1)/3
    double Ih2 = 0;
    double Ih1 = 0;
    /*for(int i = 0; i < n; i++) {
        Soma += A[i]*f.run(x[i]);
    }*/
    //LEMBRANDO QUE AQUI O N É O H
    Ih2 = (f.run(left) + f.run(right))*n/4;
    Ih1 = (f.run(left) + f.run(right))*n/2;
    setArea(4*Ih2/3 - Ih1/3);

    return true;
}
