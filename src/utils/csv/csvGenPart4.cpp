#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../../methods/runge-kutta/RungeKutta.h"
#include "../../methods/adams/Adams.h"
#include "../../common/sample-initial-value.h"

using namespace std;


void csvEntries();

int main(int argc, char *argv[])
{

    // Read samples from file and store them
    SampleInitialValue *sampleIV = new SampleInitialValue();
    sampleIV->readSamplesFromFile(argv[1]);
    
    // Vectors to store the results we want to compare
    std::vector<point> resultsRK2;
    std::vector<point> resultsRK3;
    std::vector<point> resultsRK4;
    std::vector<point> resultsA3;
    std::vector<point> resultsA4;
    
    // Starting CVS
    ofstream csv ("src/utils/csv/table.csv"); 
    
    csv << "-, Solution, RK 2,  RK 3, RK 4, Adams 3, Adams 4\n";
    csv << "ti, f(ti) \n";


    // Storing results
    resultsRK2.clear();
    resultsRK2 = RungeKutta::secondOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );
resultsRK4.clear();
    resultsRK4 = RungeKutta::fourthOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    resultsA3 = Adams::thirdOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    resultsA4 = Adams::fourthOrder(
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    // ---------------------------------------------------

    for (int i = 0; i < resultsRK2.size(); i++)
    {
        csv << resultsRK2[i].x    << ", " 
               << resultsRK2[i].y << ", " 
               << resultsRK3[i].y << ", " 
               << resultsRK4[i].y << ", " 
               << resultsA3[i].y  << ", " 
               << resultsA4[i].y  << "\n";
    }
    
    csv.close();

    return 0;
}