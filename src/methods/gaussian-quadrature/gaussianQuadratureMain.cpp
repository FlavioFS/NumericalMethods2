#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../includes/IMethod.h"
#include "../../common/sampleOpen.h"
#include "gaussianQuadrature.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleOpen *sampleOP = new SampleOpen();
    sampleOP->readSamplesFromFile(argv[1]);

    GaussianQuadrature gaussianQuadrature ( sampleOP->getFunction(), sampleOP->getN(),
                             sampleOP->getLeft(), sampleOP->getRight());
    gaussianQuadrature.run();

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << " Gaussian-Quadrature | " << setw(10) << gaussianQuadrature.getArea()
         << endl << "____________________________" << endl;

    return 0;
}
