#include "regularPower.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
RegularPower::RegularPower(Matrix A, int order, double e)
    : A(A), order(order), e(e)
{
}

/* ==========================================================
                             Sets
========================================================== */
void RegularPower::setMartrix(Matrix A)
{
    this->A = A;
}

void RegularPower::setOrder(const unsigned int order)
{
    this->order = order;
}

void RegularPower::setE(const double e) 
{
    this->e = e;
}

// Private
void RegularPower::setArea(double area)
{
    this->area = area;
}

/* ==========================================================
                             Gets
========================================================== */
double RegularPower::getArea() { return area; }

/* ==========================================================
                             Run
========================================================== */
bool RegularPower::run()
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


    Matrix Zk(order, 1);

    // Used to store the actual lambda
    Matrix aux(1,1);

    do {

        yk_before = yk_after;
        Zk = (A * qk);
        qk = Zk * (1/Zk.normalize());
        aux = qk.transpose() * A * qk;
        yk_after = aux.get(1,1);
 
      // Checks the convergence
    } while (abs((yk_after - yk_before)) > e);

    cout
    << endl << "__________________________________"
    << endl << "Dominant Eigenvector Approximation"
    << endl << "__________________________________"
    << endl <<endl << qk
    << endl << "__________________________________"
    <<endl << endl;

    setArea(yk_after);

    return true;
}
