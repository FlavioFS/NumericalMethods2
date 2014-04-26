#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../Derivative.h"

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

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    if ( fileRead(argv[1]) )
    {
        Function f;
        f.pushBackFunction(f1);
        f.pushBackFunction(f2);
        f.pushBackFunction(f3);
        f.pushBackFunction(f4);
        f.pickFunction(functionChosen);

        double result = Derivative::backRichardson(f, value, spacing, true);
        
        // TODO put this on the view logic
        cout << endl << "Derivative by Backward Difference method with Richardson Extrapolation: " << result << endl;
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
        // Reads info
        inFile >> spacing;
        inFile >> functionChosen;
        inFile >> value;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "Input path ...... '" << filePath       << "'"    << endl
             << "Spacing ......... '" << spacing        << "'"    << endl
             << "Function chosen . '" << functionChosen << "'"    << endl
             << "Value ........... '" << value          << "'"    << endl
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
