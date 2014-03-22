#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "../IMethod.h"
#include "sampleMultipleIntegral.h"
#include "multipleIntegral.h"

using namespace std;

int main(int argc, char *argv[])
{

    // Read samples from file and store them
    SampleMultipleIntegral *sampleMI = new SampleMultipleIntegral();
    sampleMI->readSamplesFromFile("entrada5.txt");


    MultipleIntegral *mIntegral = new MultipleIntegral(sampleMI->getSamples(), sampleMI->getHx(), sampleMI->getHy());
    mIntegral->run();

   
    // TODO put this on the view logic
    /*cout << endl << "Areas"
         << endl << "____________________________"
         << endl << "  Trapezio    | " << setw(10) << trapezoidal.getArea()
         << endl << "  1/3 Simpsom | " << setw(10) << simpsom13.getArea()
         << endl << "  3/8 Simpsom | " << setw(10) << simpson38.getArea()
         << endl << " Newton-Cotes | " << setw(10) << newtonCotes.getArea()
         << endl << "____________________________" << endl;*/

    return 0;
}

