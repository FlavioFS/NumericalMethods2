#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../../common/sampleClosed.h"
#include "simpsons13.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleClosed *sampleCL = new SampleClosed();
    sampleCL->readSamplesFromFile("sample_closed.txt");

    Simpsons13 simpsom13 (sampleCL->getSamples());
    simpsom13.run();

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << "  1/3 Simpsom | " << setw(10) << simpsom13.getArea()
         << endl << "____________________________" << endl;

    return 0;
}

