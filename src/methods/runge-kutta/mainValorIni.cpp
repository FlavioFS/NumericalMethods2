#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "RungeKutta.h"
#include "../adams/Adams.h"
#include "../../common/sample-initial-value.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Read samples from file and store them

    SampleInitialValue *sampleIV = new SampleInitialValue();
    sampleIV->readSamplesFromFile(argv[1]);
    std::vector<point> results;
    ofstream script;

    //Starting Octave Script
    script.open ("scriptOctave.m");
    script << "figure;\n";
    if(sampleIV->getFunctionID() == 1)
    {
        script << "a = ezplot(\"e^(0.25*x^4-1.5*x)\",[" << sampleIV->getLeft() << "," << sampleIV->getRight() << "])\n"
               << "set(a,\"linewidth\",2)\n"
               << "set(a,\"color\",\"k\")\n"
               << "grid on\n"
               << "hold on\n";
    }

    else if(sampleIV->getFunctionID() == 2)
    {
        script << "a = ezplot(\"((2*x^2+x+2)^2)/4\",[" << sampleIV->getLeft() << "," << sampleIV->getRight() << "])\n"
               << "set(a,\"linewidth\",2)\n"
               << "set(a,\"color\",\"k\")\n"
               << "grid on\n"
               << "hold on\n";        
    }

    else if(sampleIV->getFunctionID() == 3)
    {
        script << "a = ezplot(\"(2*x^2-2*x+3*e^(-2*x)+1)/4\",[" << sampleIV->getLeft() << "," << sampleIV->getRight() << "])\n"
               << "set(a,\"linewidth\",2)\n"
               << "set(a,\"color\",\"k\")\n"
               << "grid on\n"
               << "hold on\n";        
    }

    //Second Order Runge Kutta, showing results and writing octave script 
    results.clear();
    results = RungeKutta::secondOrder(sampleIV->getFunction(), 
                                            sampleIV->getV0(), 
                                            sampleIV->getH(), 
                                            sampleIV->getLeft(), 
                                            sampleIV->getRight());

    script << "trk2 = [";

    for (int i = 0; i < results.size(); i++)
    {
        if(results[i].x != sampleIV->getRight())
        {
            script << results[i].x << ",";
        }
        else
        {
            script << results[i].x << "]\n";
        }
    }
        
    script << "yrk2 = [";

    cout << "Second Order Runge Kutta: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script

        if(results[i].x != sampleIV->getRight())
        {
            script << results[i].y << ",";
        }
        else
        {
            script << results[i].y << "]\n";
        }

    }
    cout << "================================================================" << endl << endl;

    script << "rk2 = plot(trk2, yrk2)\n"
           << "set(rk2,\"linewidth\",2)\n"
           << "set(rk2,\"color\",\"b\")\n"
           << "hold on\n";

    //Third Order Runge Kutta, showing results and writing octave script
    results.clear();
    results = RungeKutta::thirdOrder(sampleIV->getFunction(), 
                                            sampleIV->getV0(), 
                                            sampleIV->getH(), 
                                            sampleIV->getLeft(), 
                                            sampleIV->getRight());

    script << "trk3 = [";

    for (int i = 0; i < results.size(); i++)
    {
        if(results[i].x != sampleIV->getRight())
        {
            script << results[i].x << ",";
        }
        else
        {
            script << results[i].x << "]\n";
        }
    }

    script << "yrk3 = [";

    cout << "Third Order Runge Kutta: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;

        if(results[i].x != sampleIV->getRight())
        {
            script << results[i].y << ",";
        }
        else
        {
            script << results[i].y << "]\n";
        }

    }
    cout << "================================================================" << endl << endl;

    script << "rk3 = plot(trk3, yrk3, \"r-\")\n"
           << "set(rk3,\"linewidth\",2)\n"
           << "hold on\n";

    //Third Order Adams, showing results and writing octave script 
    results.clear();
    results = Adams::thirdOrder(sampleIV->getFunction(), 
                                            sampleIV->getV0(), 
                                            sampleIV->getH(), 
                                            sampleIV->getLeft(), 
                                            sampleIV->getRight());

    script << "tad3 = [";

    for (int i = 0; i < results.size(); i++)
    {
        if(results[i].x != sampleIV->getRight())
        {
            script << results[i].x << ",";
        }
        else
        {
            script << results[i].x << "]\n";
        }
    }

    script << "yad3 = [";

    cout << "Third Order Adams: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;

        if(results[i].x != sampleIV->getRight())
        {
            script << results[i].y << ",";
        }
        else
        {
            script << results[i].y << "]\n";
        }

    }
    cout << "================================================================" << endl << endl;

    script << "ad3 = plot(tad3, yad3, \"g-\")\n"
           << "set(ad3,\"linewidth\",2)\n"
           << "legend('solucao analitica','Forward Euler', 'RK2', 'RK3');";
    script.close();

    return 0;
}