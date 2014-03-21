#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleClosed.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleClosed::SampleClosed()
{}

/* ==========================================================
                             Gets
========================================================== */
std::vector<point> SampleClosed::getSamples()
{ return this->samples; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleClosed::readSamplesFromFile(const char* filePath)
{
    ifstream sampleFile (filePath);

    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (sampleFile.good())
    {
        unsigned int
            head,
            i = 0;

        // Reads the header
        sampleFile >> head;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "Input path ...... '" << filePath << "'" << endl
             << "Point amount .... " << head << endl;


        // Reads the body (points)
        while (sampleFile.good())
        {
            point in;
            sampleFile >> in.x >> in.y;
            i++;
            samples.push_back(in);

            cout << setw(3) << i << "| "
                 << "("<< in.x << "," << in.y << ")" << endl;
        }

        cout << "===============================================" << endl;
    }

    // No
    else if (samples.empty())
    {
        cout << "This file does not contain samples." << endl;
        return false;
    }

    return true;
}
