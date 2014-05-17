#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

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

/* ==========================================================
                            Function List
    ========================================================== */

// Expecting to receive v and t as parameters, in that order.
// Ex: f(v, t)
// params[0] = v, and params[1] = t
double SampleInitialValue::f1(std::vector<double> params) { return (params[0]*pow(params[1], 3)) - (1.5*params[1]); }
double SampleInitialValue::f2(std::vector<double> params) { return (1+(4*params[1]))*sqrt(params[0]); }
double SampleInitialValue::f3(std::vector<double> params) { return (2*params[0]) + pow(params[1], 2); }