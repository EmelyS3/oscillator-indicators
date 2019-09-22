#ifndef AROONOSCILLATOR_H
#define AROONOSCILLATOR_H

#include <iostream>

typedef struct _AroonOscillatorVal
{
    double *result;
    int retCode;
} AroonOscillatorVal, *P_ARRAY_AROONOSCILLATORVAL;


class AroonOscillator
{
public:
    AroonOscillator();

    P_ARRAY_AROONOSCILLATORVAL AroonOscillatorCalc(double *high,
                                            double *low,
                                            int nPeriods);
};

#endif // AROONOSCILLATOR_H
