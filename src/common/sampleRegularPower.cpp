#include <iostream>
#include <fstream>
#include <iomanip>

#include "sampleRegularPower.h"

using namespace std;


/* ==========================================================
                         Constructors
========================================================== */
SampleRegularPower::SampleRegularPower()
{
   
}

/* ==========================================================
                             Gets
========================================================== */
Matrix SampleRegularPower::getSamples()
{ return this->samples; }

double SampleRegularPower::getE()
{ return this->e; }

int SampleRegularPower::getOrder()
{ return this->order; }

/* ==========================================================
                             Sets
========================================================== */
void SampleRegularPower::setE(double e)
{ this->e = e; }

void SampleRegularPower::setOrder(int order)
{ this->order = order; }

/* ==========================================================
                             Logic
========================================================== */
bool SampleRegularPower::readSamplesFromFile(const char* filePath)
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

        /* +-----------------------------------+ *
        * | Read the u here, for shifted power | *
        * +------------------------------------+ */

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "================ Regular Power ================" << endl
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
