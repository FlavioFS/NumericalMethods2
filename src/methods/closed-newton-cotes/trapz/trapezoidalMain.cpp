#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../../common/sampleClosed.h"
#include "trapezoidal.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleClosed *sampleCL = new SampleClosed();
    sampleCL->readSamplesFromFile("sample_closed.txt");

    Trapezoidal trapezoidal (sampleCL->getSamples());
    trapezoidal.run();

    // TODO put this on the view logic
    cout << endl << "Area"
         << endl << "____________________________"
         << endl << "  Trapezio    | " << setw(10) << trapezoidal.getArea()
         << endl << "____________________________" << endl;

    return 0;
}

