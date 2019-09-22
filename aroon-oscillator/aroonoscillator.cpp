#include "aroonoscillator.h"

AroonOscillator::AroonOscillator()
{

}


P_ARRAY_AROONOSCILLATORVAL AroonOscillator::AroonOscillatorCalc(double *high,
                                        double *low,
                                        int nPeriods)
{

    P_ARRAY_AROONOSCILLATORVAL ret;
    double *resUp = (double *) malloc(1*sizeof(double *));
    double *resDown = (double *) malloc(1*sizeof(double *));

    ret = (P_ARRAY_AROONOSCILLATORVAL) malloc(1*sizeof(P_ARRAY_AROONOSCILLATORVAL));
    ret->result = (double *) malloc(nPeriods*sizeof(double *));

    for(int a = 0; a < nPeriods; a++)
    {
        resUp[0] = 100 * (25 - high[a]) / 25;
        std::cout << resUp[0] << std::endl;

        resDown[0] = 100 * (25 - low[a]) / 25;
        std::cout << resDown[0] << std::endl;

        ret->result[a] = resUp[0] - resDown[0];
    }

    return ret;
}
