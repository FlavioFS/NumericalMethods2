#ifndef SAMPLE_INITIAL_VALUE_H
#define SAMPLE_INITIAL_VALUE_H

#include "../includes/ISample.h"
#include "FunctionRn.h"

class SampleInitialValue : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleInitialValue();

    /* ==========================================================
                                 Gets
    ========================================================== */
    FunctionRn getFunction();
    double getV0();
    double getLeft();
    double getRight();

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    FunctionRn f;         // Continuous function
    double v0;          // v′ = f(v, t) and v(0) = v0
    double h;           // h
    double left, right; // Interval borders
};

#endif // SAMPLE_INITIAL_VALUE_H
