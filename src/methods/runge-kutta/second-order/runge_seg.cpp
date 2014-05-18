#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../RungeKutta.h"
#include "../../../common/sample-initial-value.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Read samples from file and store them

    SampleInitialValue *sampleIV = new SampleInitialValue();
    sampleIV->readSamplesFromFile(argv[1]);

    double result = RungeKutta::secondOrder(sampleIV->getFunction(), 
                                            sampleIV->getV0(), 
                                            sampleIV->getH(), 
                                            sampleIV->getLeft(), 
                                            sampleIV->getRight());
        
    cout << "Second Order Runge Kutta: " <<             result                 << endl
         << "================================================================" << endl;

    return 0;
}
