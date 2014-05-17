#include <iostream>
#include <fstream>
#include <iomanip>

#include "sample-initial-value.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleInitialValue::SampleInitialValue()
{}

/* ==========================================================
                             Gets
========================================================== */
Function SampleInitialValue::getFunction() { return f; }
double SampleInitialValue::getV0() { return v0; }
double SampleInitialValue::getLeft() { return left; }
double SampleInitialValue::getRight() { return right; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleInitialValue::readSamplesFromFile(const char* filePath)
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
        sampleFile >> v0;

        // TODO: Function selection
        sampleFile >> functionNumber;

        // h (or Delta t)
        sampleFile >> h;

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
             << "V0 ......................... " << v0                            << endl
             << "h .......................... " << h                            << endl
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
