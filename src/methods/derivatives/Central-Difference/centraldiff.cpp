#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../derivatives/Derivative.h"

using namespace std;

bool fileRead(const char* filePath);

double f1(double x) { return ( -0.1*powf(x,4) - 0.15*powf(x,3) - 0.5*powf(x,2) - 0.25*x + 1.2 ); }
double f2(double x) { return ( 2*powf(x,4) - 6*powf(x,3) - 12*x - 8 ); }
double f3(double x) { return ( 2*powf(x,3) + 3*powf(x,2) +  6*x + 1 ); }
double f4(double x) { return ( 1 - x - 4*powf(x,3) + 2*powf(x,5) ); }

// Global variables
unsigned int
    functionChosen;

double
    value = 0,      // x value 
    spacing = 1;    // spacing between the points

bool
    higherPrecision = false;  // Higher precision enabled?

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    if ( fileRead(argv[1] )
    {
        Function f;
        f.pushBackFunction(f1);
        f.pushBackFunction(f2);
        f.pushBackFunction(f3);
        f.pushBackFunction(f4);
        f.pickFunction(functionChosen);

        double result = Derivative::centralDiff(f, value, spacing, higherPrecision);
        
        // TODO put this on the view logic
        cout << endl << "Derivative by Central Difference method: " << result << endl;
    }

    return 0;
}

bool fileRead(const char* filePath)
{
    ifstream inFile (filePath);

    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (inFile.good())
    {
        unsigned int pointAmount;

        // Reads info
        inFile >> pointAmount;
        inFile >> functionChosen;
        inFile >> spacing;
        inFile >> value;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "Input path ...... '" << filePath    << "'"       << endl
             << "Point amount .... '" << pointAmount << "'"       << endl
             << "Spacing ......... '" << spacing     << "'"       << endl
             << "Value ........... '" << value       << "'"       << endl
             << "===============================================" << endl;

        if (pointAmount != 3)
            {higherPrecision = true};
    }

    // No
    else
    {
        cout << "Invalid file." << endl;
        return false;
    }

    return true;
}
