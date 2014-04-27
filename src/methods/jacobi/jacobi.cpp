#include "jacobi.h"
#include <cmath>
#include <cstdio>
#include <iostream>

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
    Matrix Pk(order, order+1);
    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            if( i == j)
            {
                Pk >> 1;
                P >> 1;
            }
            else
            {
                Pk >> 0;
                P >> 0;
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
                   if(A.get(i,i) != A.get(j,j))
                   {
                       teta = (atan(2*A.get(i,j)/(A.get(i,i) - A.get(j,j))))/2;
                   }
                   else teta = PI/4;

                   Pk.put(cos(teta), i, i);
                   Pk.put(sin(teta), j, i);
                   Pk.put(-sin(teta), i, j);
                   Pk.put(cos(teta), j, j);

                   A = Pk.transpose()*A*Pk;
                   P = P*Pk;
                }
            }
        }

        for(int i = 0; i < order; i++)
        {
            for(int j = 0; j< order; j++)
            {
                if(i != j)
                {
                    soma = soma + A.get(i,j);
                }
            }
        }
    }
    return true;

}
