#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleRomberg.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleRomberg::SampleRomberg()
{}

/* ==========================================================
                             Gets
========================================================== */
Function SampleRomberg::getFunction() { return f; }
double SampleRomberg::getN() { return n; }
double SampleRomberg::getLeft() { return left; }
double SampleRomberg::getRight() { return right; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleRomberg::readSamplesFromFile(const char* filePath)
{
    ifstream sampleFile (filePath);

    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (sampleFile.good())
    {
        unsigned int functionNumber;

        // Interval division
        sampleFile >> n;

        // Function selection
        sampleFile >> functionNumber;
        f.setFunction(functionNumber);

        // Left and Right bounds
        sampleFile >> left;
        sampleFile >> right;

        // Left and right swapped
        if (left > right)
        {
            double aux = left;
            left = right;
            right = aux;
        }

        // Feedback
        cout << endl
             << "=============================================================" << endl
             << "Input path ................. '" << filePath << "'"             << endl
             << "Function ID................. " << functionNumber               << endl
             << "H value..................... " << n                            << endl
             << "Interval ................... [" << left << "," << right << "]" << endl
             << "=============================================================" << endl;
    }

    // No
    else
    {
        cout << "Invalid file." << endl;
        return false;
    }

    return true;
}
