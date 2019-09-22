#ifndef AROON_H
#define AROON_H

#include <iostream>

typedef struct _AroonValues
{
    double *up;
    double *down;
    int retCode;
} AroonValues, *P_ARRAY_AROONVALUES;



class Aroon
{

public:

    P_ARRAY_AROONVALUES AroonCalc(double *up,
                                  double *down,
                                  int nPeriod);
    Aroon();

};

#endif // AROON_H
