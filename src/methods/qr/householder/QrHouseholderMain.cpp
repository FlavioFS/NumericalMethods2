#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../../common/sampleQr.h"
#include "qrHouseholder.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleQr *sampleQR = new SampleQr();
    sampleQR->readSamplesFromFile(argv[1]);

    qrHouseholder qrH ( sampleQR->getSamples(), sampleQR->getOrder(), sampleQR->getE());
    qrH.run();

    // TODO put this on the view logic
    cout << endl << "Eigenvalue Matrix"
         << endl << "____________________________"
         << endl << qrH.getA()
         << endl << "____________________________" << endl;

    cout << endl << "Eigenvector Matrix"
         << endl << "____________________________"
         << endl << qrH.getP()
         << endl << "____________________________" << endl;

    return 0;
}
