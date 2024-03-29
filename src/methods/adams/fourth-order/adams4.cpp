#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../Adams.h"
#include "../../../common/sample-initial-value.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Read samples from file and store them
    SampleInitialValue *sampleIV = new SampleInitialValue();
    sampleIV->readSamplesFromFile(argv[1]);

    vector<point> result = Adams::fourthOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );
    
    const unsigned int width = 13;
    cout << "======================= Fourth Order Adams =====================" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout <<  "(" << setw(width) << result[i].x << ", " << setw(width) << result[i].y << ")" << endl;
    }
    cout << "================================================================" << endl;

    return 0;
}
