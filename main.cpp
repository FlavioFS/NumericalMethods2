#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "IMethod.h"
#include "sampleClosed.h"
#include "sampleOpen.h"
#include "trapezoidal.h"
#include "simpsons38.h"
#include "simpsons13.h"
#include "newtonCotes.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{

    // Read samples from file and store them
    SampleClosed *sampleCL = new SampleClosed();
    sampleCL->readSamplesFromFile("closed.txt");

    SampleOpen *sampleOP = new SampleOpen();
    sampleOP->readSamplesFromFile("open.txt");

    /* +----------------------------------------------------------+ *
     * |In the future, call shoud be like this:                   | *
     * | IMethod *method =  new Trapezoidal(sample->getSamples());| *
     * +----------------------------------------------------------+ */

    Trapezoidal trapezoidal (sampleCL->getSamples());
    trapezoidal.run();

    Simpsons13 simpsom13 (sampleCL->getSamples());
    simpsom13.run();

    Simpsons38 simpson38 (sampleCL->getSamples());
    simpson38.run();

    NewtonCotes newtonCotes ( sampleOP->getFunction(), sampleOP->getN(),
                             sampleOP->getLeft(), sampleOP->getRight());

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << "  Trapezio    | " << setw(10) << trapezoidal.getArea()
         << endl << "  1/3 Simpsom | " << setw(10) << simpsom13.getArea()
         << endl << "  3/8 Simpsom | " << setw(10) << simpson38.getArea()
         << endl << " Newton-Cotes | " << setw(10) << newtonCotes.getArea()
         << endl << "____________________________" << endl;

    return 0;
}

