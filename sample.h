#ifndef SAMPLE_H
#define SAMPLE_H

#include "function.h"

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
    std::vector<function> getSamples();

    /* ==========================================================
                                 Logic
    ========================================================== */
    bool readSamplesFromFile(char* filePath);

private:

    std::vector<function> samples;   // Function (Discrete sample)

};

#endif // SAMPLE_H
