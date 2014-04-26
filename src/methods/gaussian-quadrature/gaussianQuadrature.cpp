#include "gaussianQuadrature.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
GaussianQuadrature::GaussianQuadrature(Function f, int n, double left, double right)
    : f(f), n(n), left(left), right(right)
{
    //Xi's
    //x [5] = {0,0,0,0,0};

    //Ti's
    //t [5] = {0,0,0,0,0};

    //Ai's
    //A [5] = {0,0,0,0,0};

    //setando os Ti's e Ai's
    if(n == 2) {
        t[0] = -0.57735;
        t[1] = 0.57735;

        A[0] = 1;
        A[1] = 1;
    }
    if(n == 3) {
        t[0] = -0.77459;
        t[1] = 0;
        t[2] = 0.77459;

        A[0] = 0.55556;
        A[1] = 0.88889;
        A[2] = 0.55556;
    }
    if(n == 4) {
        t[0] = -0.86113;
        t[1] = -0.33998;
        t[2] = 0.33998;
        t[3] = 0.86113;

        A[0] = 0.34785;
        A[1] = 0.65214;
        A[2] = 0.65214;
        A[3] = 0.34785;
    }
    if(n == 5) {
        t[0] = -0.90617;
        t[1] = -0.53846;
        t[2] = 0;
        t[3] = 0.53846;
        t[4] = 0.90617;

        A[0] = 0.23692;
        A[1] = 0.47862;
        A[2] = 0.56889;
        A[3] = 0.47862;
        A[4] = 0.23692;
    }

    //setando os Xi's
    for(int i = 0; i < n ; i++ ) {
        x[i] = t[i]*(right - left)/2 + (left + right)/2;
    }
}

/* ==========================================================
                             Sets
========================================================== */
void GaussianQuadrature::setFunction(Function f)
{
    this->f = f;
}

void GaussianQuadrature::setN(const unsigned int n)
{
    this->n = n;
}

// Private
void GaussianQuadrature::setArea(double area)
{
    this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double GaussianQuadrature::getArea() { return area; }

/* ==========================================================
                             Run
========================================================== */
bool GaussianQuadrature::run()
{

    double Soma = 0;


   /* for (int i = 1; i < n+2; i++)
    {
        Sn += coefficientsMap(n, i)*f.run(left+i*h);
    }*/
    for(int i = 0; i < n; i++) {
        Soma += A[i]*f.run(x[i]);
    }
    setArea((right - left)*Soma/2);

    return true;
}
