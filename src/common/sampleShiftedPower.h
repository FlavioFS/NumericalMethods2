#ifndef SAMPLE_SHIFTED_POWER_H
#define SAMPLE_SHIFTED_POWER_H

#include "../includes/ISample.h"
#include "Matrix.h"
#include <vector>

using namespace std;

class SampleShiftedPower : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleShiftedPower();

    /* ==========================================================
                                 Gets
    ========================================================== */
    Matrix getSamples();
   
    double getE();

    double getU();

    int getOrder();

    /* ==========================================================
                                 Sets
    ========================================================== */

    void setE(double e);

    void setU(double u);

    void setOrder(int order);

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    Matrix samples;         // The matrix we want the eigenvalues
    double e;               // The tolerance
    unsigned int order;     // Matrix order
    double u;               // Value we want the eigenvalue to be next to.

};

#endif // SAMPLE_SHIFTED_POWER_H
