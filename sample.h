#ifndef SAMPLE_H
#define SAMPLE_H

#include "point.h"
#include <vector>

class Sample
{

public:

    /* ==========================================================
                             Constructors
    ========================================================== */
    Sample();

    /* ==========================================================
                                 Gets
    ========================================================== */
    std::vector<point> getSamples();

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(const char* filePath, unsigned const int headerSize);

private:

    std::vector<point> samples;             // Discrete sample of points
    std::vector<unsigned int> header; // Header of sample

};

#endif // SAMPLE_H
