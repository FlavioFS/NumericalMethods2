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
    bool readSamplesFromFile(char* filePath);

private:

    std::vector<point> samples;   // Function (Discrete sample)

};

#endif // SAMPLE_H
