#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../../common/sampleRomberg.h"
#include "romberg.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    SampleRomberg *sampleOP = new SampleRomberg();
    sampleOP->readSamplesFromFile(argv[1]);

    Romberg romberg ( sampleOP->getFunction(), sampleOP->getN(),
                             sampleOP->getLeft(), sampleOP->getRight());
    romberg.run();

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << " Romberg | " << setw(10) << romberg.getArea()
         << endl << "____________________________" << endl;

    return 0;
}
