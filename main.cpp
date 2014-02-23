#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "IMethod.h"
#include "Sample.h"
#include "Trapezoidal.h"

using namespace std;

bool testMethod();

int main()
{

    // Read samples from file and store them
    Sample *sample = new Sample();
    sample->readSamplesFromFile();

    // In the future, call shoud be like this:
    // IMethod *method =  new Trapezoidal(sample->getSamples());
    
    Trapezoidal method (sample->getSamples());
    method.run();
    // TOO put this on the view logic
    cout << endl << "Area: " << method.getArea();
    
    return 0;
}

