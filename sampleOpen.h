#ifndef SAMPLE_OPEN_H
#define SAMPLE_OPEN_H

#include "ISample.h"
#include "Function.h"

class SampleOpen : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleOpen();

    /* ==========================================================
                                 Gets
    ========================================================== */
    Function getFunction();
    unsigned int getN();
    double getLeft();
    double getRight();

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    Function f;         // Continuous function
    unsigned int n;     // Interval segmentation count
    double left, right; // Interval borders
};

#endif // SAMPLE_OPEN_H
