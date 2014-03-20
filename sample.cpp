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
std::vector<point> Sample::getSamples()
{ return this->samples; }

std::vector<unsigned int> Sample::getHeader()
{ return this->header; }

/* ==========================================================
                             Logic
========================================================== */
bool Sample::readSamplesFromFile(const char* filePath, unsigned const int headerSize)
{
    ifstream sampleFile (filePath);

    unsigned int
        head,
        i = 0;


    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (sampleFile.good())
    {
        // Reads the header
        for (int i = 0; i < headerSize; i++)
        {
            sampleFile >> head;
            this->header.push_back(head);
        }

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
    }

    // No
    else if (samples.empty())
    {
        cout << "This file does not contain samples." << endl;
        return false;
    }

    return true;
}
