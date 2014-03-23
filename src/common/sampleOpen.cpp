#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleOpen.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleOpen::SampleOpen()
{}

/* ==========================================================
                             Gets
========================================================== */
Function SampleOpen::getFunction() { return f; }
unsigned int SampleOpen::getN() { return n; }
double SampleOpen::getLeft() { return left; }
double SampleOpen::getRight() { return right; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleOpen::readSamplesFromFile(const char* filePath)
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
        unsigned int functionNumber;

        // Interval division
        sampleFile >> n;
        if (n > 4)
            { n = 4; }
        else if (n < 1)
            { n = 1; }

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
            right = left;
        }

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "Input path ...... '" << filePath << "'" << endl
             << "Function ID ..... " << functionNumber << endl
             << "Interval count .. " << n << endl
             << "Interval ........ [" << left << "," << right << "]" << endl
             << "===============================================" << endl;
    }

    // No
    else
    {
        cout << "Invalid file." << endl;
        return false;
    }

    return true;
}
