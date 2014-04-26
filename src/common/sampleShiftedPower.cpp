#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleShiftedPower.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleShiftedPower::SampleShiftedPower()
{
   
}

/* ==========================================================
                             Gets
========================================================== */
Matrix SampleShiftedPower::getSamples()
{ return this->samples; }

double SampleShiftedPower::getE()
{ return this->e; }

double SampleShiftedPower::getU()
{ return this->u; }

int SampleShiftedPower::getOrder()
{ return this->order; }

/* ==========================================================
                             Sets
========================================================== */
void SampleShiftedPower::setE(double e)
{ this->e = e; }

void SampleShiftedPower::setU(double u)
{ this->u = u; }

void SampleShiftedPower::setOrder(int order)
{ this->order = order; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleShiftedPower::readSamplesFromFile(const char* filePath)
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

        // Reads the u
        sampleFile >> this->u;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "================ ==== Power ===================" << endl
             << "===============================================" << endl << endl
             << "Input path ....... '" << filePath << "'" << endl
             << "Matrix Order ..... " << getOrder() << endl
             << "Tolerance ........ " << getE() << endl
             << "u ................ " << getU() << endl
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
