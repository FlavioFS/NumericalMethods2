#ifndef SAMPLE_POWER_H
#define SAMPLE_POWER_H

#include "../includes/ISample.h"
#include "Matrix.h"
#include <vector>

using namespace std;

class SamplePower : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SamplePower();

    /* ==========================================================
                                 Gets
    ========================================================== */
    Matrix getSamples();
   
    double getE();

    int getOrder();

    /* ==========================================================
                                 Sets
    ========================================================== */

    void setE(double e);

    void setOrder(int order);

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    Matrix samples; // Discrete sample of points
    double e; // The tolerance
    unsigned int order; // Matrix order

};

#endif // SAMPLE_POWER_H
