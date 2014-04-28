#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../common/sampleJacobi.h"
#include "Jacobi.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleJacobi *sampleJA = new SampleJacobi();
    sampleJA->readSamplesFromFile(argv[1]);

    Jacobi jacobi ( sampleJA->getSamples(), sampleJA->getOrder(), sampleJA->getE());
    jacobi.run();

    // TODO put this on the view logic
    cout << endl << "Eigenvalue Matrix"
         << endl << "____________________________"
         << endl << jacobi.getA()
         << endl << "____________________________" << endl;

    cout << endl << "Eigenvector Matrix"
         << endl << "____________________________"
         << endl << jacobi.getP()
         << endl << "____________________________" << endl;

    return 0;
}
