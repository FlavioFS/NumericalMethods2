#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "../../methods/runge-kutta/RungeKutta.h"
#include "../../methods/adams/Adams.h"
#include "../../common/sample-initial-value.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Read samples from file and store them

    SampleInitialValue *sampleIV = new SampleInitialValue();
    sampleIV->readSamplesFromFile(argv[1]);
    std::vector<point> results;
    ofstream script ("src/utils/octave/scriptOctave.m"); //Starting Octave Script


    script << "figure;\n";

    // ------------------ Function name ------------------
    if(sampleIV->getFunctionID() == 1)
    {
        script << "a = ezplot(\"e^(0.25*x^4 - 1.5*x)\",[" << sampleIV->getLeft() << "," << sampleIV->getRight() << "])\n"
               << "set(a,\"linewidth\",2)\n"
               << "set(a,\"color\",\"k\")\n"
               << "grid on\n"
               << "hold on\n";
    }

    else if(sampleIV->getFunctionID() == 2)
    {
        script << "a = ezplot(\"((2*x^2 + x + 2)^2)/4\",[" << sampleIV->getLeft() << "," << sampleIV->getRight() << "])\n"
               << "set(a,\"linewidth\",2)\n"
               << "set(a,\"color\",\"k\")\n"
               << "grid on\n"
               << "hold on\n";        
    }

    else if(sampleIV->getFunctionID() == 3)
    {
        script << "a = ezplot(\"(2*x^2 - 2*x + 3*e^(-2*x) + 1)/4\",[" << sampleIV->getLeft() << "," << sampleIV->getRight() << "])\n"
               << "set(a,\"linewidth\",2)\n"
               << "set(a,\"color\",\"k\")\n"
               << "grid on\n"
               << "hold on\n";        
    }
    // ---------------------------------------------------

    // Forward Euler, showing results and writing octave script 
    results.clear();
    results = RungeKutta::firstOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    script << "teuler = [";

    for (int i = 0; i < results.size() - 1; i++)
    {
        script << results[i].x << ", ";
    }
    script << results.back().x << "]\n";
        
    script << "yeuler = [";

    cout << "\nForward Euler: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size() - 1; i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script
        script << results[i].y << ", ";
    }
    cout <<  "f(" << setw(4) << results.back().x << ") = " << setw(13) << results.back().y << endl;
    script << results.back().y << "]\n";
    cout << "================================================================" << endl << endl;

    script << "euler = plot(teuler, yeuler, \"b--\")\n"
           << "set(euler,\"linewidth\",2)\n"
           << "hold on\n";
    // ---------------------------------------------------

    // Second Order Runge Kutta, showing results and writing octave script 
    results.clear();
    results = RungeKutta::secondOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    script << "trk2 = [";

    for (int i = 0; i < results.size() - 1; i++)
    {
        script << results[i].x << ", ";
    }
    script << results.back().x << "]\n";
        
    script << "yrk2 = [";

    cout << "\nSecond Order Runge Kutta: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size() - 1; i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script
        script << results[i].y << ", ";
    }
    cout <<  "f(" << setw(4) << results.back().x << ") = " << setw(13) << results.back().y << endl;
    script << results.back().y << "]\n";
    cout << "================================================================" << endl << endl;

    script << "rk2 = plot(trk2, yrk2, \"b-\")\n"
           << "set(rk2,\"linewidth\",2)\n"
           << "hold on\n";
    // ---------------------------------------------------

    // Third Order Runge Kutta, showing results and writing octave script
    results.clear();
    results = RungeKutta::thirdOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    script << "trk3 = [";

    for (int i = 0; i < results.size() - 1; i++)
    {
        script << results[i].x << ", ";
    }
    script << results.back().x << "]\n";

    script << "yrk3 = [";

    cout << "Third Order Runge Kutta: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size() - 1; i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script
        script << results[i].y << ", ";
    }
    cout <<  "f(" << setw(4) << results.back().x << ") = " << setw(13) << results.back().y << endl;
    script << results.back().y << "]\n";
    cout << "================================================================" << endl << endl;

    script << "rk3 = plot(trk3, yrk3, \"r-\")\n"
           << "set(rk3,\"linewidth\",2)\n"
           << "hold on\n";
    // ---------------------------------------------------

    // Fourth Order Runge Kutta, showing results and writing octave script
    results.clear();
    results = RungeKutta::fourthOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    script << "trk4 = [";

    for (int i = 0; i < results.size() - 1; i++)
    {
        script << results[i].x << ", ";
    }
    script << results.back().x << "]\n";

    script << "yrk4 = [";

    cout << "Fourth Order Runge Kutta: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size() - 1; i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script
        script << results[i].y << ", ";
    }
    cout <<  "f(" << setw(4) << results.back().x << ") = " << setw(13) << results.back().y << endl;
    script << results.back().y << "]\n";
    cout << "================================================================" << endl << endl;

    script << "rk4 = plot(trk4, yrk4, \"m-\")\n"
           << "set(rk4,\"linewidth\",2)\n"
           << "hold on\n";
    // ---------------------------------------------------

    // Third Order Adams, showing results and writing octave script 
    results.clear();
    results = Adams::thirdOrder (
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    script << "tad3 = [";

    for (int i = 0; i < results.size() - 1; i++)
    {
        script << results[i].x << ", ";
    }
    script << results.back().x << "]\n";

    script << "yad3 = [";

    cout << "Third Order Adams: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size() - 1; i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script
        script << results[i].y << ", ";
    }
    cout <<  "f(" << setw(4) << results.back().x << ") = " << setw(13) << results.back().y << endl;
    script << results.back().y << "]\n";
    cout << "================================================================" << endl << endl;

    script << "ad3 = plot(tad3, yad3, \"g-\")\n"
           << "set(ad3,\"linewidth\",2)\n"
           << "hold on\n";
    // ---------------------------------------------------

    // Fourth Order Adams, showing results and writing octave script 
    results.clear();
    results = Adams::fourthOrder(
        sampleIV->getFunction(), 
        sampleIV->getV0(), 
        sampleIV->getH(), 
        sampleIV->getLeft(), 
        sampleIV->getRight()
    );

    script << "tad4 = [";

    for (int i = 0; i < results.size() - 1; i++)
    {
        script << results[i].x << ", ";
    }
    script << results.back().x << "]\n";

    script << "yad4 = [";

    cout << "Fourth Order Adams: " << endl
         << "================================================================" << endl;
    for (int i = 0; i < results.size() - 1; i++)
    {
        //Printing on screen
        cout <<  "f(" << setw(4) << results[i].x << ") = " << setw(13) << results[i].y << endl;
        //Writing on script
        script << results[i].y << ", ";
    }
    cout <<  "f(" << setw(4) << results.back().x << ") = " << setw(13) << results.back().y << endl;
    script << results.back().y << "]\n";
    cout << "================================================================" << endl << endl;

    script << "ad4 = plot(tad4, yad4, \"c-\")\n"
           << "set(ad4,\"linewidth\",2)\n"
           << "legend('solucao analitica', 'Euler', 'RK2', 'RK3', 'RK4', 'Adams3', 'Adams4');";
    script.close();

    return 0;
}