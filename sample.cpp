#include <iostream>
#include <fstream>
#include <iomanip>

#include "sample.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
Sample::Sample()
{}

/* ==========================================================
                             Gets
========================================================== */
std::vector<function> Sample::getSamples()
{ return this->samples; }

/* ==========================================================
                             Logic
========================================================== */
bool Sample::readSamplesFromFile(char* filePath)
{
    ifstream sampleFile (filePath);

    unsigned int
        intervals = 0,
        i = 0;

    // File ok?
    // Yes

    if (sampleFile.good())
    {
        // Point amount
        sampleFile >> intervals;

        // Load points
        while (sampleFile.good())
        {
            function in;
            sampleFile >> in.x >> in.y;
            i++;
            samples.push_back(in);

            cout << setw(3) << i << "| "
                 << "("<< in.x << "," << in.y << ")" << endl;
        }
    }
    // No
    else if (samples.empty())
    {
        cout << "This file does not contain samples." << endl;
        return false;
    }

    return true;
}
