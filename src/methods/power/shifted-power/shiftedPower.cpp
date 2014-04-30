#include "shiftedPower.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
ShiftedPower::ShiftedPower(Matrix A, int order, double e, double u)
    : A(A), order(order), e(e), u(u)
{
    qk.resize(order,1);
}

/* ==========================================================
                             Sets
========================================================== */
void ShiftedPower::setMatrix(Matrix A)
{
    this->A = A;
}

void ShiftedPower::setOrder(const unsigned int order)
{
    this->order = order;
}

void ShiftedPower::setE(const double e)
{
    this->e = e;
}

void ShiftedPower::setU(const double u)
{
    this->u = u;
}

// Private
void ShiftedPower::setEigenvalue(double value)
{
    this->eigenvalue = value;
}

/* ==========================================================
                             Gets
========================================================== */
double ShiftedPower::getEigenvalue() const { return eigenvalue; }
const Matrix ShiftedPower::getEigenvector() const { return qk; }

/* ==========================================================
                             Run
========================================================== */
bool ShiftedPower::run()
{
    qk.resize(order, 1);
    double yk_before = 0;
    double yk_after = 0;

    /*+----------------------------------------+ *
    * | Building initial q0                    | *
    * | q0 must be a nonzero vector in R^n.    | *
    * | We particulary build q0 by adding zeros| *
    * | and 1 at the last position.            | *
    * +----------------------------------------+ */
    qk.put(1, order,1);

    /*+----------------------------------------+ *
    * | Building new A.                        | *
    * | We subtract u on the diagonal          | *
    * +----------------------------------------+ */
    for (unsigned int i = 0; i < order; i++) {
        A.put(A.get(i+1, i+1)-u, i+1, i+1);    
    }

    // Builds the A matrix to solve AX = b, using LU
    double *A;
    A = new double[order*order]; int count = 0;
    for (unsigned int i = 0; i < order; ++i)
    {   
        for (unsigned int j = 0; j < order; ++j) {
            A[count] = this->A.get(i+1, j+1); count++;
        }

    }

    // Building the new qk vector to pass to LU. 
    // qk represents 'b', on the system AX = b.
    double *B1;
    B1 = new double[order];
    for (unsigned int i = 0; i < order; ++i)
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
        for (unsigned int i = 0; i < order; ++i)
        {
            B[i] = qk.get(i+1, 1);
        }

        // Change B on LU decomposition
        lu->setB(B);

        Zk = lu->applyLU();
        qk = Zk * (1/Zk.normalize());
        aux = qk.transpose() * this->A * qk;
        yk_after = aux.get(1,1) + u;
 
      // Checks the convergence
    } while (abs((yk_after - yk_before)) > e);

    setEigenvalue(yk_after);
/*
    cout
    << endl << "__________________________________"
    << endl << "Eigenvector Approximation"
    << endl << "__________________________________"
    << endl << endl << qk;
    
    cout << endl << "Vector format:" << endl << endl;
    cout << "[" ;
    unsigned int i;
    for (i = 1; i <= order-1; ++i)
    {
       cout << qk.get(i, 1) << ", ";
    }
    cout << qk.get(i, 1);
    cout << "]" ;

    cout << endl << "__________________________________"
    << endl <<endl << endl;
  */
    return true;
}
