#ifndef MFI_H
#define MFI_H

#include <iostream>
#include <QDebug>

#define NULL_VALUE -1000

typedef struct _MFIVal
{
    double *tPrice;
    double *upDown;
    double *rawMF;
    double *oneDPeriodPosMF;
    double *oneDPeriodNegMF;
    double *fourTDPeriodPosMF;
    double *fourTDPeriodNegMF;
    double *fourTDPeriodMFRat;
    double *fourTDPeriodMFInd;
    int retCode;
} MFIVal, *P_ARRAY_CCIVAL;


class MFI
{
public:
    MFI();

    P_ARRAY_CCIVAL MFICalc(double *high,
                           double *low,
                           double *close,
                           double *vol,
                           int totalItems);
};

#endif // MFI_H
