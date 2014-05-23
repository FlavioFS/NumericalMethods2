#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../../methods/runge-kutta/RungeKutta.h"
#include "../../methods/adams/Adams.h"
#include "../../common/sample-initial-value.h"
#include "../../common/Function.h"

using namespace std;


static double f1 (double x);
static double f2 (double x);
static double f3 (double x);

double f1 (double x) { return exp( 0.25*pow(x, 4) - 1.5*x  ); }
// + ou - ?
double f2 (double x) { return 1/4 * pow( (2*pow(x, 2) + x + 2), 2 ); }
double f3 (double x) { return 1/4 * (2*pow(x, 2) - 2*x + 3*exp(-2*x) + 1); }


int main(int argc, char *argv[])
{

    // Read samples from file and store them
    SampleInitialValue *sampleIV = new SampleInitialValue();
    sampleIV->readSamplesFromFile(argv[1]);
    
    // Vectors to store the results we want to compare
    std::vector<point> resultsEuler;
    std::vector<point> resultsRK2;
    std::vector<point> resultsRK3;
    std::vector<point> resultsRK4;
    std::vector<point> resultsA3;
    std::vector<point> resultsA4;
    
    // Starting CVS
    ofstream csv ("src/utils/csv/table.csv"); 
    
    csv << "-, Solution, Euler, RK 2,  RK 3, RK 4, Adams 3, Adams 4\n";
    csv << "ti, f(ti) \n";


    // Storing results

    resultsEuler = RungeKutta::firstOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    resultsRK2 = RungeKutta::secondOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    resultsRK3 = RungeKutta::thirdOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

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


    Function f;
    f.pushBackFunction(f1);
    f.pushBackFunction(f2);
    f.pushBackFunction(f3);
    f.pickFunction(sampleIV->getFunctionID());


    for (int i = 0; i < resultsRK2.size(); i++)
    {
        csv    << resultsA4[i].x    << ", " 
               << f.run(resultsRK2[i].x) << ", " 
               << resultsEuler[i].y << ", " 
               << resultsRK2[i].y << ", " 
               << resultsRK3[i].y << ", " 
               << resultsRK4[i].y << ", " 
               << resultsA3[i].y  << ", " 
               << resultsA4[i].y  << "\n";
    }

    csv.close();

    return 0;
}