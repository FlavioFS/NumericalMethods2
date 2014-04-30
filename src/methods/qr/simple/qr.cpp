#include "qr.h"
#include <cmath>

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
void Qr::setMatrix(Matrix A)
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
    P = Matrix::identity(order);
    Matrix Pk = P;
    Matrix Qt = P; // Qt = Pkt*Qt
    Matrix R = A;

    while(soma > e)
    {
        soma = 0;
        for(unsigned int i = 1; i <= order; i++)
        {
            for(unsigned int j = 1; j <= order; j++)
            {
                if(i > j)
                {
                   double
                       ajj = A.get(j,j),
                       aij = A.get(i,j),
                       denominator = sqrt(aij*aij + ajj*ajj);

                   Pk.put(  ( ajj / (denominator) ),  j, j );
                   Pk.put(  ( aij / (denominator) ),  i, j );
                   Pk.put( -( aij / (denominator) ),  j, i );
                   Pk.put(  ( ajj / (denominator) ),  i, i );

                   Qt = Pk.transpose()*Qt;
                   R = Pk.transpose()*R;

                   A = R*Qt.transpose();
                   P = P*Qt.transpose();

                   Pk = Matrix::identity(order);
                }
            }
        }

        for(unsigned int i = 1; i <= order; i++)
        {
            for(unsigned int j = 1; j <= order; j++)
            {
                if(i != j)
                {
                    double aij = A.get(i,j);
                    soma = soma + aij*aij;
                }
            }
        }
    }
    return true;
}