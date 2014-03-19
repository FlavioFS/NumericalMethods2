#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "IMethod.h"
#include "sample.h"
#include "trapezoidal.h"
#include "simpsons38.h"
#include "simpsons13.h"

using namespace std;

bool testMethod();

int main(int argc, char *argv[])
{

    // Read samples from file and store them
    Sample *sample = new Sample();
    sample->readSamplesFromFile("points.txt", 1);

    /* +----------------------------------------------------------+ *
     * |In the future, call shoud be like this:                   | *
     * | IMethod *method =  new Trapezoidal(sample->getSamples());| *
     * +----------------------------------------------------------+ */

    Trapezoidal trapezoidal (sample->getSamples());
    trapezoidal.run();

    Simpsons13 simpsom13 (sample->getSamples());
    simpsom13.run();

    Simpsons38 simpson38 (sample->getSamples());
    simpson38.run();

    // TODO put this on the view logic
    cout << endl << "Areas"
         << endl << "____________________________"
         << endl << "  Trapezio    | " << setw(10) << trapezoidal.getArea()
         << endl << "  1/3 Simpsom | " << setw(10) << simpsom13.getArea()
         << endl << "  3/8 Simpsom | " << setw(10) << simpson38.getArea()
         << endl << "____________________________" << endl;

    return 0;
}

