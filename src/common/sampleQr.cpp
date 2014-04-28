#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleQr.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleQr::SampleQr()
{

}

/* ==========================================================
                             Gets
========================================================== */
Matrix SampleQr::getSamples()
{ return this->samples; }

double SampleQr::getE()
{ return this->e; }

int SampleQr::getOrder()
{ return this->order; }

/* ==========================================================
                             Sets
========================================================== */
void SampleQr::setE(double e)
{ this->e = e; }

void SampleQr::setOrder(int order)
{ this->order = order; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleQr::readSamplesFromFile(const char* filePath)
{
    ifstream sampleFile (filePath);

    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (sampleFile.good())
    {

        // Used for matrix elements
        double element;

        // Reads the order
        sampleFile >> this->order;

        // Resizes the matrix to have that order.
        this->samples.resize(getOrder(), getOrder());

        // Reads order*order elements from the matrix
        for(unsigned int n = 0; n < (getOrder()*getOrder()); n++)
        {
            sampleFile >> element;
            samples >> element;
        }

        // Reads the tolerance
        sampleFile >> this->e;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "===================== QR ======================" << endl
             << "===============================================" << endl << endl
             << "Input path ....... '" << filePath << "'" << endl
             << "Matrix Order ..... " << getOrder() << endl
             << "Tolerance ........ " << getE() << endl
             << "Matrix............\n\n" << this->samples << endl
             << "===============================================" << endl;

    }
    else
    {
        cout << "Could not read the file." << endl;
        return false;
    }

    return true;
}
