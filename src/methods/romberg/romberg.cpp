#include "romberg.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
Romberg::Romberg(Function f, double h, double left, double right)
    : f(f), h(h), left(left), right(right)
{
}

/* ==========================================================
                             Sets
========================================================== */
void Romberg::setFunction(Function f)
{
    this->f = f;
}

void Romberg::setH(double h)
{
    this->h = h;
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

    double Ih2 = 0;
    double Ih1 = 0;
    /*double teste = right - left;
    //Testando se o intervalo é divisível pelo h escolhido
    if(teste%h!=0) {
        return false;
    }
    if(teste%(h/2)!=0) {
        return false;
    }*/
    double i = 0;

    for( i =  left; i < right; i = i + h/2) {
        Ih2 = Ih2 + (f.run(i) + f.run(i + h/2))*h/4;
    }
    for( i =  left; i < right; i = i + h) {
        Ih1 = Ih1 + (f.run(i) + f.run(i + h))*h/2;
    }

    /*for(int i = 0; i < n; i++) {
        Soma += A[i]*f.run(x[i]);
    }*/

    //Ih2 = (f.run(left) + f.run(right))*n/4;
    //Ih1 = (f.run(left) + f.run(right))*n/2;
    setArea(4*Ih2/3 - Ih1/3);

    return true;
}
