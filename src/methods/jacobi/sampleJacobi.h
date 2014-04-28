#ifndef JACOBI_H
#define JACOBI_H

#include "../../includes/ISample.h"
#include "../../common/Matrix.h"
#include <vector>

using namespace std;

class SampleJacobi : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleJacobi();

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

#endif //Jacobi_H
