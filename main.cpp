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
    sample->readSamplesFromFile("points.txt");

    // In the future, call shoud be like this:
    // IMethod *method =  new Trapezoidal(sample->getSamples());

    Trapezoidal trapezoidal (sample->getSamples());
    trapezoidal.run();

    Simpsons13 simpsom13 (sample->getSamples());
    simpsom13.run();

    Simpsons38 simpson38 (sample->getSamples());
    simpson38.run();

    // TODO put this on the view logic
    cout << endl << "Area| Trapezio: "    << trapezoidal.getArea()
         << endl << "Area| 1/3 Simpsom: " << simpsom13.getArea()
         << endl << "Area| 3/8 Simpsom: " << simpson38.getArea() << endl;

    return 0;
}

