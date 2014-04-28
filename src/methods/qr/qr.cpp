#include "qr.h"
#include <cmath>
#include <cstdio>
#include <iostream>

#define M_PI           3.14159265358979323846  /* pi */

using namespace std;

/* ==========================================================
                         Constructors
========================================================== */
Qr::Qr(Matrix A, int order, double e)
    : A(A), order(order), e(e)
{
}

/* ==========================================================
                             Sets
========================================================== */
void Qr::setMartrix(Matrix A)
{
    this->A = A;
}

void Qr::setOrder(const unsigned int order)
{
    this->order = order;
}

void Qr::setE(const double e)
{
    this->e = e;
}

/* ==========================================================
                             Gets
========================================================== */
Matrix Qr::getA() { return A; }

Matrix Qr::getP() { return P; }

/* ==========================================================
                             Run
========================================================== */
bool Qr::run()
{
   // double teta = 0;
    double soma = 1000;
    P.resize(order,order);
    Matrix Pk(order, order);
    Matrix R(order, order);
    R = A;
    Matrix Qt(order, order); // Qt = Pkt*Qt
    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            if( i == j)
            {
                Pk.put(1,i+1,i+1);
                P.put(1,i+1,i+1);
                Qt.put(1,i+1,i+1);
            }
            else
            {
                Pk.put(0,i+1,j+1);
                P.put(0,i+1,j+1);
                Qt.put(0,i+1,j+1);
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
                if(i > j)
                {
                  // if(A.get(i+1,i+1) != A.get(j+1,j+1))
                   //{
                     //  teta = (atan(2*A.get(i+1,j+1)/(A.get(i+1,i+1) - A.get(j+1,j+1))))/2;
                   //}
                   //else teta = M_PI/4;

                   Pk.put((A.get(j+1,j+1)/(sqrt(A.get(i+1,j+1)*A.get(i+1,j+1)+A.get(j+1,j+1)*A.get(j+1,j+1)))), j+1, j+1);
                   Pk.put((A.get(i+1,j+1)/(sqrt(A.get(i+1,j+1)*A.get(i+1,j+1)+A.get(j+1,j+1)*A.get(j+1,j+1)))), i+1, j+1);
                   Pk.put(-(A.get(i+1,j+1)/(sqrt(A.get(i+1,j+1)*A.get(i+1,j+1)+A.get(j+1,j+1)*A.get(j+1,j+1)))), j+1, i+1);
                   Pk.put((A.get(j+1,j+1)/(sqrt(A.get(i+1,j+1)*A.get(i+1,j+1)+A.get(j+1,j+1)*A.get(j+1,j+1)))), i+1, i+1);

                  // cout << "Pk: " << endl;
                   //cout << Pk << endl;
                   Qt = Pk.transpose()*Qt;
                   R = Pk.transpose()*R;

                   A = R*Qt.transpose();
                   P = P*Qt.transpose();

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
