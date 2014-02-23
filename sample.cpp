#include <iostream>
#include <fstream>
#include <iomanip>

#include "Sample.h"

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
bool Sample::readSamplesFromFile()
{
    ifstream sampleFile ("function.txt");

    unsigned int
        intervals = 0,
        i = 0;

    if (sampleFile.good())
    {
        sampleFile >> intervals;
    }

    while (sampleFile.good())
    {
        function in;
        sampleFile >> in.x >> in.y;
        i++;
        samples.push_back(in);

        cout << setw(3) << i << "| "
             << "("<< in.x << "," << in.y << ")" << endl;
    }

    if (samples.empty())
    {
        cout << "This file does not contain samples." << endl;
        return false;
    }

    return true;
}
