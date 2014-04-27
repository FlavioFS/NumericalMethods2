#ifndef SAMPLE_ROMBERG_H
#define SAMPLE_ROMBERG_H

#include "../../includes/ISample.h"
#include "../../common/Function.h"

class SampleRomberg : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleRomberg();

    /* ==========================================================
                                 Gets
    ========================================================== */
    Function getFunction();
    double getN();
    double getLeft();
    double getRight();

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    Function f;         // Continuous function
    double n;     // Interval segmentation count
    double left, right; // Interval borders
};

#endif // SAMPLE_ROMBERG_H
