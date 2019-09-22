#include "aroon.h"

Aroon::Aroon()
{

}


P_ARRAY_AROONVALUES Aroon::AroonCalc(double *up,
                                     double *down,
                                     int nPeriods)
{
    P_ARRAY_AROONVALUES ret = (P_ARRAY_AROONVALUES) malloc(1*(sizeof(P_ARRAY_AROONVALUES)));

    ret->up = (double *) malloc(nPeriods * sizeof(double *));
    ret->down = (double *) malloc(nPeriods * sizeof(double *));
    double v1;
    double v2;
    double v3;

    for(int i = 0; i < nPeriods; i++)
    {

        v1 = 25 - up[i];
        v2 = v1  / 25;
        v3 = v2 * 100;
        ret->up[i] = v3;

        v1 = 25 - down[i];
        v2 = v1 / 25;
        v3 = v2 * 100;
        ret->down[i] = v3;

    }

    return ret;
}
