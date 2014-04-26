#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../../common/sampleShiftedPower.h"
#include "shiftedPower.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleShiftedPower *sampleSP = new SampleShiftedPower();
    sampleSP->readSamplesFromFile(argv[1]);

    ShiftedPower shiftedPower ( sampleSP->getSamples(), sampleSP->getOrder(), sampleSP->getE(), sampleSP->getU());
    shiftedPower.run();

    // TODO put this on the view logic
    cout << endl << "Eigenvalue"
         << endl << "____________________________"
         << endl << " Shifted Power | " << setw(10) << shiftedPower.getArea()
         << endl << "____________________________" << endl;

    return 0;
}
