#ifndef CCI_H
#define CCI_H

#include <iostream>
#include <QDebug>

typedef struct _CCIVal
{
    double *tp;
    double *result;
    double *sma20TP;
    double *sma20MD;
    double *sma20CCI;
    int retCode;
} CCIVal, *P_ARRAY_CCIVAL;


class CCI
{

public:
    CCI();

    void OperArray(double *sma20tp,
                        double *tp,
                        int indx,
                        double *ret);

    void avg(double *vals, int initPos, int finalPos, double *ret);

    P_ARRAY_CCIVAL CCICalc(double *close,
                           double *high,
                           double *low,
                           int nPeriods);

};

#endif // CCI_H
