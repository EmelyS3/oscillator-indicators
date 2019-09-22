#ifndef BOLLINGERBANDWIDTH_H
#define BOLLINGERBANDWIDTH_H

#include <iostream>


typedef struct _BBWVal
{
    double *result;
    int retCode;
} BBWVal, *P_ARRAY_BBW;




class BollingerBandWidth
{
public:
    BollingerBandWidth();
    P_ARRAY_BBW BBWCalc(double *uBand, double *lBand, double *mBand);
};

#endif // BOLLINGERBANDWIDTH_H
