#include "inversePower.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
InversePower::InversePower(Matrix A, int order, double e)
    : A(A), order(order), e(e)
{
}

/* ==========================================================
                             Sets
========================================================== */
void InversePower::setMartrix(Matrix A)
{
    this->A = A;
}

void InversePower::setOrder(const unsigned int order)
{
    this->order = order;
}

void InversePower::setE(const double e) 
{
    this->e = e;
}

// Private
void InversePower::setArea(double area)
{
    this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double InversePower::getArea() { return area; }

/* ==========================================================
                             Run
========================================================== */
bool InversePower::run()
{
    double yk_before = 0;
    double yk_after = 0;

    /*+----------------------------------------+ *
    * | Building initial q0                    | *
    * | q0 must be a nonzero vector in R^n.    | *
    * | We particulary build q0 by adding zeros| *
    * | and 1 at the last position.            | *
    * +----------------------------------------+ */
    Matrix qk(order, 1);
    for(int i = 0; i < order-1; i++) 
    {
        qk >> 0;
    }
    qk >> 1;


    // Used to store the actual lambda
    /*Matrix aux(1,1);

    do {

        yk_before = yk_after;
        Zk = (A * qk);
        qk = Zk * (1/Zk.normalize());
        aux = qk.transpose() * A * qk;
        yk_after = aux.get(1,1);
 
      // Checks the convergence
    } while (abs((yk_after - yk_before)) > e);

    setArea(yk_after);*/

    return true;
}
