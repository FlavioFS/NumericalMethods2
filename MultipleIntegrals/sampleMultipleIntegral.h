#ifndef SAMPLE_MULTIPLE_INTEGRAL_H
#define SAMPLE_MULTIPLE_INTEGRAL_H

#include "../ISample.h"
#include <vector>

using namespace std;

class SampleMultipleIntegral : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleMultipleIntegral();

    /* ==========================================================
                                 Gets
    ========================================================== */
    double** getSamples();

    void initializeMatrix();

    double getHx();

    double getHy();

    /* ==========================================================
                                 Sets
    ========================================================== */

    void setHx(double hx);

    void setHy(double hy);

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    double** samples; // Discrete sample of points
    double hx, hy; // Used to calculate h

};

#endif // SAMPLE_MULTIPLE_INTEGRAL_H
