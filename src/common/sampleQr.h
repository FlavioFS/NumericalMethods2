#ifndef QR_H
#define QR_H

#include "../includes/ISample.h"
#include "Matrix.h"
#include <vector>

using namespace std;

class SampleQr : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleQr();

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

#endif //QR_H
