#ifndef IMETHOD_H
#define IMETHOD_H

#include "point.h"

/* This interface should be used by the other methods */
class IMethod
{
    public:

        /* TODO: Decidir o tipo de retorno e parâmetros, de acordo com as necessidades */
        virtual bool run() = 0;

    protected:

    private:
};

#endif // IMETHOD_H
