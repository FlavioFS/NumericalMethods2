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
FunctionRn SampleInitialValue::getFunction() { return f; }
int SampleInitialValue::getFunctionID() {return functionID;}
double SampleInitialValue::getV0() { return v0; }
double SampleInitialValue::getH() { return h; }
double SampleInitialValue::getLeft() { return left; }
double SampleInitialValue::getRight() { return right; }

/* ==========================================================
                            Function List
    ========================================================== */

// Expecting to receive v and t as parameters, in that order.
// Ex: f(v, t)
// params[0] = v, and params[1] = t
double f1(std::vector<double> params) { return (params[0]*pow(params[1], 3)) - (1.5*params[0]); }
double f2(std::vector<double> params) { return (1+(4*params[1]))*sqrt(params[0]); }
double f3(std::vector<double> params) { return (2*params[0]) + pow(params[1], 2); }

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

        // Function selection
        sampleFile >> functionNumber;
        functionID = functionNumber;
        if (functionNumber == 1) {
            f.setFunction(f1);
        } else if(functionNumber == 2) {
            f.setFunction(f2);
        } else if(functionNumber == 3) {
            f.setFunction(f3);
        }

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

