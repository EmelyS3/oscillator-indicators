#ifndef PERCENTAGEB_H
#define PERCENTAGEB_H

#include <iostream>

typedef struct _PBVal
{
    double *result;
    int retCode;
} PBVal, *P_ARRAY_PBVAL;


class PercentageB
{
public:

    PercentageB();

    P_ARRAY_PBVAL PBCalc(double *price,
               double *lBand,
               double *uBand, int nPeriods);
};

#endif // PERCENTAGEB_H
