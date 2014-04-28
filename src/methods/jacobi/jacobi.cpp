#include "jacobi.h"
#include <cmath>
#include <cstdio>
#include <iostream>

#define M_PI           3.14159265358979323846  /* pi */

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
Jacobi::Jacobi(Matrix A, int order, double e)
    : A(A), order(order), e(e)
{
}

/* ==========================================================
                             Sets
========================================================== */
void Jacobi::setMartrix(Matrix A)
{
    this->A = A;
}

void Jacobi::setOrder(const unsigned int order)
{
    this->order = order;
}

void Jacobi::setE(const double e)
{
    this->e = e;
}

/* ==========================================================
                             Gets
========================================================== */
Matrix Jacobi::getA() { return A; }

Matrix Jacobi::getP() { return P; }

/* ==========================================================
                             Run
========================================================== */
bool Jacobi::run()
{
    double teta = 0;
    double soma = 1000;
    P.resize(order,order);
    Matrix Pk(order, order);
    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            if( i == j)
            {
                Pk.put(1,i+1,i+1);
                P.put(1,i+1,i+1);
            }
            else
            {
                Pk.put(0,i+1,j+1);
                P.put(0,i+1,j+1);
            }
        }
    }

    while(soma > e)
    {
        soma = 0;
        for(int i = 0; i < order; i++)
        {
            for(int j = 0; j < order; j++)
            {
                if(j > i)
                {
                   if(A.get(i+1,i+1) != A.get(j+1,j+1))
                   {
                       teta = (atan(2*A.get(i+1,j+1)/(A.get(i+1,i+1) - A.get(j+1,j+1))))/2;
                   }
                   else teta = M_PI/4;

                   Pk.put(cos(teta), i+1, i+1);
                   Pk.put(sin(teta), j+1, i+1);
                   Pk.put(-sin(teta), i+1, j+1);
                   Pk.put(cos(teta), j+1, j+1);

                  // cout << "Pk: " << endl;
                   //cout << Pk << endl;

                   A = Pk.transpose()*A*Pk;
                   P = P*Pk;

                 //  cout << "P: " << endl;
                  // cout << P << endl;
                  // cout << "A: " << endl;
                  // cout << A << endl;
                    for(int i = 0; i < order; i++)
                    {
                        for(int j = 0; j < order; j++)
                        {
                            if( i == j)
                            {
                                Pk.put(1,i+1,i+1);
                               // P.put(1,i+1,i+1);
                            }
                            else
                            {
                                Pk.put(0,i+1,j+1);
                               // P.put(0,i+1,j+1);
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < order; i++)
        {
            for(int j = 0; j< order; j++)
            {
                if(i != j)
                {
                    soma = soma + A.get(i+1,j+1)*A.get(i+1,j+1);
                }
            }
        }
    }
    return true;

}
