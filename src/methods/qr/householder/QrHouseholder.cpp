#include "qrHouseholder.h"
#include <cmath>
#include <iostream>

/* ==========================================================
                         Constructors
========================================================== */
QrHouseholder::QrHouseholder(Matrix A, int order, double e)
: Qr(A, order, e)
{
}

Matrix QrHouseholder::getHouseholded()
{
    return householded;
}

/* ==========================================================
                             Run
========================================================== */
bool QrHouseholder::run()
{
/*-----------------------Householder--------------------*/
    unsigned int n = A.rows();
    for (unsigned int k = 1; k < n; k++)
    {
        // Modulus
        double s = 0;
        for (unsigned int j = k+1; j <= n; j++)
        {
            double a_jk = A.get(j, k);
            s += a_jk*a_jk;
        }
        double a = A.get(k+1, k);
        s = sqrt(s)*(-a/fabs(a));

        double r = sqrt((s-a)*s/2);

        Matrix v (n, 1);
        for (unsigned int j = k+1; j <= n; j++)
        {
            double value;

            if (j == k+1)
                { value = (a - s)/(2*r);}
            else
                { value = A.get(j, k)/(2*r);}

            v.put(value, j,1);
        }

        Matrix I = Matrix::identity(n);
        Matrix Q = I - (v*v.transpose())*2;
        A = Q*A*Q;
    }
/*---------------------QR-------------------*/
    householded = A;
    Qr::run();
    return true;
}
