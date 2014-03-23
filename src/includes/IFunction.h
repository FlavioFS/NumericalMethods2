#ifndef IFUNCTION_H
#define IFUNCTION_H

/*  Interface: Function
 *  Describes what an object needs to be a function
 */
class IFunction
{
    public:
        // Runs function using 'x' as the argument and returns f(x)
        virtual double run(double x) =0;
};

#endif // IFUNCTION_H
