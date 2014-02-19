#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#include "IMethod.h"
#include <vector>

class Trapezoidal : public IMethod
{
public:
    Trapezoidal(double left, double right, int resolution);

    void setLeft(double);
    void setRight(double);
    bool setResolution(unsigned int);

    void correctAttributes();

    double run();

private:
    double
        left,
        right,
        area;

    unsigned int
        resolution;
};

#endif // TRAPEZOIDAL_H
