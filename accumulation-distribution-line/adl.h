#ifndef ADL_H
#define ADL_H

#include <iostream>
#include <math.h>

typedef struct _ADLRetValues
{
    double *mFMultipler;
    double *mFValue;
    double *aDLine;
    int retCode;
} ADLValues, *P_ARRAY_ADLVALUES;


class ADL
{
public:

    double *CalcMfMutl(double high,
                   double low,
                   double close);

    P_ARRAY_ADLVALUES Calculate(double *high,
                  double *low,
                  double *close,
                  double *volume, int maxIndex);
    ADL();
};

#endif // ADL_H
