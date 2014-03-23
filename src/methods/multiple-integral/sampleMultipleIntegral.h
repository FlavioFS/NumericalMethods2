#ifndef SAMPLE_MULTIPLE_INTEGRAL_H
#define SAMPLE_MULTIPLE_INTEGRAL_H

#include "../../includes/ISample.h"
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

    unsigned int getMx();

    unsigned int getMy();

    /* ==========================================================
                                 Sets
    ========================================================== */

    void setHx(double hx);

    void setHy(double hy);

    void setMx(unsigned int mx);

    void setMy(unsigned int my);

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    double** samples; // Discrete sample of points
    double hx, hy; // Used to calculate h
    unsigned int mx, my; // x and y dimensions

};

#endif // SAMPLE_MULTIPLE_INTEGRAL_H
