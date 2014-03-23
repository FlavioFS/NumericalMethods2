#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../../common/sampleClosed.h"
#include "simpsons38.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleClosed *sampleCL = new SampleClosed();
    sampleCL->readSamplesFromFile("sample_closed.txt");

    Simpsons38 simpson38 (sampleCL->getSamples());
    simpson38.run();

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << "  3/8 Simpsom | " << setw(10) << simpson38.getArea()
         << endl << "____________________________" << endl;

    return 0;
}

