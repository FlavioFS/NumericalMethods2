#include <iostream>
#include <fstream>
#include <iomanip>

#include "../derivatives/Derivative.h"

using namespace std;

bool fileRead(const char* filePath);

// Global variables
vector<point> points;
double value;

int main(int argc, char *argv[])
{
    // Read samples from file and store them
    if ( fileRead(argv[1] )
    {
        double result = Derivative::lagrangeDiff(points, value);
        
        // TODO put this on the view logic
        cout << endl << "Derivative by Lagrange Method: " << result << endl;
    }

    return 0;
}

bool fileRead(const char* filePath)
{
    ifstream inFile (filePath);

    /* +------------------------+ *
     * | Is the sample file ok? | *
     * +------------------------+ */

    // Yes
    if (inFile.good())
    {
        unsigned int head;

        // Reads the point amount
        inFile >> head;

        // Feedback
        cout << endl
             << "===============================================" << endl
             << "Input path ...... '" << filePath << "'"          << endl;

        // Reads the body (points)
        for (int i = 0; i < head; i++)
        {
            if (inFile.good())
            {
                point in;
                inFile >> in.x >> in.y;
                i++;
                samples.push_back(in);

                cout << setw(3) << i << "| "
                     << "("<< in.x << "," << in.y << ")" << endl;
            }
        }

        inFile >> value;
        cout << "Value ........... '" << value << "'"             << endl
             << "===============================================" << endl;
    }

    // No
    else
    {
        cout << "Invalid file." << endl;
        return false;
    }

    return true;
}
