#include "cci.h"

CCI::CCI()
{

}

void CCI::OperArray(double *sma20tp, double *tp,
                    int indx, double *ret)
{

    double resultAbs[indx];
    double resultSum = 0;


    for(int a = indx; a != -1; a--)
    {
        resultAbs[a] = abs(sma20tp[indx] - tp[a]);
    }

    for(int e = 0; e <= indx; e++)
    {
        resultSum = resultSum + resultAbs[e];
    }

    ret = &resultSum;
}


void CCI::avg(double *vals, int initPos, int finalPos,
              double *ret)
{
    double sum = 0;
    int totalItems = finalPos - initPos;
    double retFn = 0;

    for(int a = initPos; a < finalPos; a++)
    {
        sum = sum + vals[a];        
    }        

    retFn = sum / totalItems;
}


P_ARRAY_CCIVAL CCI::CCICalc(
                            double *close,
                            double *high,
                            double *low,
                            int nPeriods)
{

    P_ARRAY_CCIVAL ret = (P_ARRAY_CCIVAL) malloc(1 * sizeof(P_ARRAY_CCIVAL));
    ret->sma20CCI = (double *) malloc(nPeriods * sizeof(double *));
    ret->sma20MD = (double *) malloc(nPeriods * sizeof(double *));
    ret->sma20TP = (double *) malloc(nPeriods * sizeof(double *));
    ret->tp = (double *) malloc(nPeriods * sizeof(double *));
    int firstIndx = 0;
    int lastIndx = 21;
    double avgResult;
    
    for(int i = 0; i < nPeriods; i++)
    {

        ret->tp[i] = (high[i] + low[i] + close[i]) / 3;        

        if(i >= 19)
        {
            // 20-day SMA of TP
            avg(ret->tp, firstIndx, lastIndx, &avgResult);
            ret->sma20TP[i] = avgResult;

            // 20-day Mean Deviation
            OperArray(ret->sma20TP, ret->tp, i, &ret->sma20MD[i]);

            // 20-day CCI
            ret->sma20CCI[i] = (ret->tp[i] - ret->sma20TP[i])
                                / (0.015 * ret->sma20MD[i]);

            firstIndx++;
            lastIndx++;
        }

            else
            {
                ret->sma20TP[i] = -1000;
            }
    }

    return ret;

}

