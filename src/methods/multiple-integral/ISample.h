#ifndef ISAMPLE_H
#define ISAMPLE_H

#include "../../includes/point.h"
#include <vector>

class ISample
{

public:

    /* ==========================================================
                                 Logic
    ========================================================== */
    virtual bool readSamplesFromFile(const char* filePath) = 0;

private:

};

#endif // ISAMPLE_H
