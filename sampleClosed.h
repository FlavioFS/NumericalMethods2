#ifndef SAMPLE_CLOSED_H
#define SAMPLE_CLOSED_H

#include "ISample.h"
#include "point.h"
#include <vector>

class SampleClosed : public ISample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    SampleClosed();

    /* ==========================================================
                                 Gets
    ========================================================== */
    std::vector<point> getSamples();

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath);

private:

    std::vector<point> samples; // Discrete sample of points
};

#endif // SAMPLE_CLOSED_H
