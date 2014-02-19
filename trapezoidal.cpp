#include "trapezoidal.h"

Trapezoidal::Trapezoidal()
    : Trapezoidal (0,0,1)
{}

Trapezoidal::Trapezoidal(double left, double right, int resolution)
    : left(left), right(right), resolution(resolution)
{
    correctAttributes();
}

void Trapezoidal::setLeft(double left)
    { this->left = left; }

void Trapezoidal::setRight(double right)
    { this->right = right; }

void Trapezoidal::setResolution(unsigned int resolution)
    { this->resolution = resolution; }

void Trapezoidal::correctAttributes()
{
    if (right < left)
    {
        double aux = right;
        right = left;
        left = aux;
    }
}

double Trapezoidal::run()
{
}
