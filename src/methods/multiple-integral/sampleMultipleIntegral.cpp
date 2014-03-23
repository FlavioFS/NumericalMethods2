#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleMultipleIntegral.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleMultipleIntegral::SampleMultipleIntegral()
{}

/* ==========================================================
                             Gets
========================================================== */
double** SampleMultipleIntegral::getSamples()
{ return this->samples; }

double SampleMultipleIntegral::getHx()
{ return this->hx; }

double SampleMultipleIntegral::getHy()
{ return this->hy; }

 unsigned int SampleMultipleIntegral::getMx()
 { return this->mx; }

 unsigned int SampleMultipleIntegral::getMy()
 { return this->my; }

/* ==========================================================
                             Sets
========================================================== */
void SampleMultipleIntegral::setHx(double hx)
{ this->hx = hx; }

void SampleMultipleIntegral::setHy(double hy)
{ this->hy = hy; }

void SampleMultipleIntegral::setMx(unsigned int mx)
{ this->mx = mx; }

void SampleMultipleIntegral::setMy(unsigned int my)
{ this->my = my; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleMultipleIntegral::readSamplesFromFile(const char* filePath)
{
    ifstream sampleFile (filePath);

    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (sampleFile.good())
    {

        // Used to calculate hx and hy
        double
            x,
            y,
            maxX = 0, 
            maxY = 0,
            minX = 0, 
            minY = 0;

        // Used for matrix indices
        unsigned int 
            i,
            j;

        // Used to x and y axes dimensions
        unsigned int
            mx,
            my;

        // Reads x and y dimensions
        sampleFile >> mx;
        sampleFile >> my;
        setMx(mx);
        setMy(my);

        // Resize matrix
        samples = new double*[mx+1];
        for (int i = 0; i <= mx; ++i)
        {
           samples[i] = new double[my+1];
        }

        // f(xi, yj)
        double
            fxy,
            value;

        // Reads the body (points)
        while (sampleFile.good())
        {
            std::vector<double> line;
           
            sampleFile >> i; 
            sampleFile >> j;
            sampleFile >> x;
            sampleFile >> y;
            sampleFile >> samples[j][i];

            if(x > maxX) {
                maxX = x;
            } else if(x < minX) {
                minX = x;
            }

            if (y > maxY)
            {
                maxY = y;
            } else if(y < minY) {
                minY = y;
            }
        }

        // Calculating h's
        setHx((maxX - minX) / mx);
        setHy((maxY - minY) / my);

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "============= Multiple Integrals ==============" << endl
             << "===============================================" << endl << endl
             << "Input path ...... '" << filePath << "'" << endl
             << "X dimension ..... " << getMx() << endl
             << "Y dimension ..... " << getMy() << endl
             << "hx .............. " << getHx() << endl
             << "hy .............. " << getHy() << endl;


        // Shows the read values on matrix
        cout << "\nRead Values.... " << endl;
        for(int i = 0; i<mx+1; i++) {
            for (int j = 0; j<my+1; j++) {
                cout << getSamples()[i][j] <<" ";
            }
            cout << endl;
        }

        cout << endl << "===============================================" << endl;
    }
    else
    {
        cout << "Could read the file." << endl;
        return false;
    }

    return true;
}
