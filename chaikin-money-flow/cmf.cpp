#include "cmf.h"


CMF::CMF()
{

}


double *CMF::DivLists(double colum1[],
                     double colum2[],
                     int maxPeriod)
{

    int i = 0;
    double *ret = (double *) malloc(maxPeriod * sizeof(double *));

    for(; i != maxPeriod; i++)
    {
        ret[i] = colum1[i] / colum2[i];
    }

    return ret;
}


P_ARRAY_RETVALUES CMF::Calculate(double *high,
                        double *low,
                        double *close,
                        double *volume,
                        int maxPeriod)
{

    RetValues *ret = (RetValues *) malloc(1*sizeof(RetValues *));
    ret->retCode -1;

    if(high == NULL || low == NULL ||
       close == NULL || volume == NULL)
    {
        return ret;
    }

    int i = 0;

    double mfMult;
    double p1;
    double p2;
    double p3;
    double p4;
    double mfVol;
    ret->mfMultipler = (double *) malloc(maxPeriod * sizeof(double *));
    ret->mfVolume = (double *) malloc(maxPeriod * sizeof(double *));
    ret->nPeriods = (double *) malloc(maxPeriod * sizeof(double *));

    for(; i <= maxPeriod; i++)
    {

        p1 = close[i] - low[i];
        p2 = high[i] - close[i];
        p3 = p1 - p2;
        p4 = high[i] - low[i];

        mfMult = p3 / p4;
        ret->mfMultipler[i] = mfMult;

        mfVol = mfMult * volume[i];
        ret->mfVolume[i] = mfVol;

        /*
            std::cout << "indx:: " << indx << std::endl;
            std::cout << "High:: " << *itH << std::endl;
            std::cout << "Low:: " << *itL << std::endl;
            std::cout << "Close:: " << *itC << std::endl;
            std::cout << "Volume:: " << *itVolume << std::endl << std::endl;
            std::cout << "CMF Mult:: " << mfMult << std::endl;
            std::cout << "CMF Vol:: " << mfVol << std::endl;
        */


        if(i == (maxPeriod -1))
        {            
            ret->nPeriods = DivLists(ret->mfVolume, volume, maxPeriod);
        }

    }

    ret->retCode = 0;

    return ret;
}
