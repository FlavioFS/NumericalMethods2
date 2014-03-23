#include <cstdio>
#include <cstdlib>
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

    double **M =  sampleMI->getSamples();
    MultipleIntegral *mIntegral = new MultipleIntegral(M,
                                                       sampleMI->getHx(), 
                                                       sampleMI->getHy(),
                                                       sampleMI->getMx(),
                                                       sampleMI->getMy());
    mIntegral->run();

    return 0;
}

