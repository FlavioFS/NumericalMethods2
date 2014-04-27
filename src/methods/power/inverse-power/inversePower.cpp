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

    // Builds the A matrix to solve AX = b, using LU
    double *A;
    A = new double[order*order]; int count = 0;
    for (int i = 0; i < order; ++i)
    {   
        for (int j = 0; j < order; ++j) {
            A[count] = this->A.get(i+1, j+1); count++;
        }

    }

    // Building the new qk vector to pass to LU. 
    // qk represents 'b', on the system AX = b.
    double *B1;
    B1 = new double[order];
    for (int i = 0; i < order; ++i)
    {
        B1[i] = qk.get(i+1, 1);
    }
 
    // Using LU to solve the system. This two matrix L and U
    // won't be recalculated. We just change qk.
    LU *lu = new LU(A, B1, order);
    lu->calcLU();

    // Used on LU. It represents x solution.
    Matrix Zk (order, 1);

    // Used to store the actual lambda
    Matrix aux(1,1);

    do {
        yk_before = yk_after;
       
        // Building the new qk vector to pass to LU. 
        // qk represents 'b', on the system AX = b.
        double *B;
        B = new double[order];
        for (int i = 0; i < order; ++i)
        {
            B[i] = qk.get(i+1, 1);
        }

        // Change B on LU decomposition
        lu->setB(B);

        Zk = lu->applyLU();
        qk = Zk * (1/Zk.normalize());
        aux = qk.transpose() * this->A * qk;
        yk_after = aux.get(1,1);
 
      // Checks the convergence
    } while (abs((yk_after - yk_before)) > e);


    cout
    << endl << "__________________________________"
    << endl << "Lowest Eigenvector Approximation"
    << endl << "__________________________________"
    << endl <<endl << qk
    << endl << "__________________________________"
    <<endl << endl;
    setArea(yk_after);

    return true;
}
