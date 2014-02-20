#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <iomanip>
#include <fstream>

#include "IMethod.h"
#include "Trapezoidal.h"

using namespace std;

bool testMethod();

int main()
{

    testMethod();

    /*

    Ex: Chamar todas as funções de convergência.
    method = new Bisseccao();
    method->run();

    */

    return 0;
}

/*   Just testing if it works while waiting for
 * the proper class to get ready.
 */
bool testMethod()
{
	std::vector<function> f;
	ifstream sample ("function.txt");

	unsigned int
        n = 0,
        i = 0;

	if (sample.good())
    {
        sample >> n;
    }

	while (sample.good())
    {
        function in;
        sample >> in.x >> in.y;
        i++;
        f.push_back(in);
        cout << setprecision(3) << i << "| "
             << setprecision(8) << "(" << in.x << "," << in.y << ")" << endl;
    }

    if (i > 0)
    {
        Trapezoidal t (f);
        t.run();
        cout << endl << "Area: " << t.getArea();
        return true;
    }
    else
    {
        cout << "Invalid file!" << endl;
        return false;
    }
}
