#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../includes/IMethod.h"
#include "../../common/sampleOpen.h"
#include "newtonCotes.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleOpen *sampleOP = new SampleOpen();
    sampleOP->readSamplesFromFile(argv[1]);

    NewtonCotes newtonCotes ( sampleOP->getFunction(), sampleOP->getN(),
                             sampleOP->getLeft(), sampleOP->getRight());
    newtonCotes.run();

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << " Newton-Cotes | " << setw(10) << newtonCotes.getArea()
         << endl << "____________________________" << endl;

    return 0;
}

