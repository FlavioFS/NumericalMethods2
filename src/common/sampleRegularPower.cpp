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

        // Used for tolerance and matrix elements
        double element;

        // Reads the order
        sampleFile >> this->order;

        // Create an auxiliary matrix to store elements
        Matrix matrix (getOrder(), getOrder());

        // Reads order*order elements of the matrix
        for(unsigned int n = 0; n < (getOrder()*getOrder()); n++)
        {
            sampleFile >> element;
            matrix >> element;
        }

        sampleFile >> this->e;
        
        /* +-----------------------------------+ *
        * | Read the u here, for shifted power | *
        * +------------------------------------+ */

        // FALTA ESSA PARTE.
        //this->samples.resize(getOrder(), getOrder());
        //this->samples = matrix;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "================ Regular Power ================" << endl
             << "===============================================" << endl << endl
             << "Input path ....... '" << filePath << "'" << endl
             << "Matrix Order ..... " << getOrder() << endl
             << "Tolerance ........ " << getE() << endl
             << "Matrix............\n\n" << matrix << endl
             << "===============================================" << endl;

    }
    else
    {
        cout << "Could not read the file." << endl;
        return false;
    }

    return true;
}
