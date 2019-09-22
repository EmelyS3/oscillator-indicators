#include "adl.h"

ADL::ADL()
{

}

double *ADL::CalcMfMutl(double high,
                        double low,
                        double close)
{

    double p1 = close - low;
    double p2 = high - close;
    double p3 = p1 - p2;
    double p4 = high - low;
    double *result = (double *) malloc(4*sizeof(double *));
    result[0] = p3 / p4;

    return result;
}

P_ARRAY_ADLVALUES ADL::Calculate(double *high,
              double *low,
              double *close,
              double *volume, int maxIndex)
{

    ADLValues *ret = (ADLValues *) malloc(1*sizeof(ADLValues *));
    ret->retCode -1;

    if(high == NULL || low == NULL ||
       close == NULL || volume == NULL)
    {
        return ret;
    }


    double *mfMult = (double *) malloc(maxIndex * sizeof(double *));
    double *retMult;
    double *retMFValue = (double *) malloc(maxIndex * sizeof(double *));
    double *retADLine = (double *) malloc(maxIndex * sizeof(double *));;

    for(int a = 0; a < maxIndex; a++)
    {
        retMult = CalcMfMutl(high[a], low[a], close[a]);
        mfMult[a] = retMult[0];
        retMFValue[a] = mfMult[a] * volume[a];

        if(a!=0)
        {
            retADLine[a] = retADLine[a-1] + retMFValue[a];
        }

            else
            {
                retADLine[0] = retMFValue[0];
            }

        retADLine[a] = retADLine[a];

    }

    ret->mFMultipler = mfMult;
    ret->mFValue = retMFValue;
    ret->aDLine = retADLine;

    return ret;
}

