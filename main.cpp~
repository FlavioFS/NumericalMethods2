#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "IMethod.h"
#include "Sample.h"
#include "Trapezoidal.h"
#include "Simpsons38.h"
#include "Simpsons13.h"

using namespace std;

bool testMethod();

int main()
{

    // Read samples from file and store them
    Sample *sample = new Sample();
    sample->readSamplesFromFile();

    // In the future, call shoud be like this:
    // IMethod *method =  new Trapezoidal(sample->getSamples());

    Trapezoidal trapezoidal (sample->getSamples());
    trapezoidal.run();
    
    Simpsons13 simpsom13 (sample->getSamples());
    simpsom13.run();

    Simpsons38 simpson38 (sample->getSamples());
    simpson38.run();

    // TODO put this on the view logic
    cout << endl << "Area| Trapezio: " << trapezoidal.getArea() << "\n";
    cout << endl << "Area| 1/3 Simpsom: " << simpsom13.getArea() << "\n";
    cout << endl << "Area| 3/8 Simpsom: " << simpson38.getArea() << "\n";

    return 0;
}

