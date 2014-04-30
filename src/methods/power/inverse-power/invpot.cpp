#include <iostream>
#include <iomanip>
#include <fstream>

#include "../../../common/samplePower.h"
#include "InversePower.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SamplePower *sampleIP = new SamplePower();
    sampleIP->readSamplesFromFile(argv[1]);

    InversePower inversePower ( sampleIP->getSamples(), sampleIP->getOrder(), sampleIP->getE());
    inversePower.run();

    // TODO put this on the view logic
    cout << endl << "Lowest Eigenvalue"
         << endl << "____________________________"
         << endl << " Inverse Power | " << setw(10) << inversePower.getEigenvalue()
         << endl << "____________________________" << endl
         << endl << "Lowest Eigenvector Approximation"
         << endl << "____________________________"
         << endl << endl << inversePower.getEigenvector()
         << endl << "____________________________"
         << endl << endl;

    return 0;
}
