#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../../common/samplePower.h"
#include "RegularPower.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SamplePower *sampleRP = new SamplePower();
    sampleRP->readSamplesFromFile(argv[1]);

    RegularPower regularPower ( sampleRP->getSamples(), sampleRP->getOrder(), sampleRP->getE());
    regularPower.run();

    // TODO put this on the view logic
    cout << endl << "Dominant Eigenvalue"
         << endl << "____________________________"
         << endl << " Regular Power | " << setw(10) << regularPower.getArea()
         << endl << "____________________________" << endl;

    return 0;
}
