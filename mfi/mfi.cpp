#include "mfi.h"

MFI::MFI()
{

}

/*
 * FIXME
 *
 * Round Typical Price
 *
 */

P_ARRAY_CCIVAL MFI::MFICalc(double *high,
                            double *low,
                            double *close,
                            double *vol,
                            int totalItems)
{

    P_ARRAY_CCIVAL ret = (P_ARRAY_CCIVAL) malloc(1 * sizeof(P_ARRAY_CCIVAL));
    ret->tPrice = (double *) malloc(totalItems  * sizeof(double *));
    ret->rawMF = (double *) malloc(totalItems  * sizeof(double *));
    ret->upDown = (double *) malloc(totalItems  * sizeof(double *));
    ret->oneDPeriodNegMF = (double *) malloc(totalItems  * sizeof(double *));
    ret->oneDPeriodPosMF = (double *) malloc(totalItems  * sizeof(double *));
    ret->fourTDPeriodPosMF = (double *) malloc(totalItems * sizeof(double *));
    ret->fourTDPeriodNegMF = (double *) malloc(totalItems * sizeof(double *));
    ret->fourTDPeriodMFInd = (double *) malloc(totalItems * sizeof(double *));
    ret->fourTDPeriodMFRat = (double *) malloc(totalItems * sizeof(double *));

    int firstFTDP = 4;
    int lastFTDP = 17;

    ret->fourTDPeriodMFInd[0] = NULL_VALUE;
    ret->fourTDPeriodMFRat[0] = NULL_VALUE;
    ret->fourTDPeriodNegMF[0] = NULL_VALUE;
    ret->fourTDPeriodPosMF[0] = NULL_VALUE;
    ret->oneDPeriodPosMF[0] = NULL_VALUE;
    ret->rawMF[0] = NULL_VALUE;
    ret->tPrice[0] = NULL_VALUE;
    ret->upDown[0] = NULL_VALUE;
    ret->oneDPeriodNegMF[0] =  NULL_VALUE;

    for(int a = 0; a < totalItems; a++)
    {

        // Typical Price
        ret->tPrice[a] = (high[a] + low[a] + close[a]) / 3;

        if( a > 0)
        {
            // Up or Down
            if(ret->tPrice[a] > ret->tPrice[a-1])
                ret->upDown[a] = 1;

            else
                ret->upDown[a] = -1;

            // Raw Money Flow
            ret->rawMF[a] = ret->tPrice[a] * vol[a];

            //1-period Positive Money Flow
            if(ret->upDown[a] > 0)
                ret->oneDPeriodPosMF[a] = ret->rawMF[a];

                else
                ret->oneDPeriodPosMF[a] = 0;

            //1-period Negative Money Flow
            if(ret->upDown[a] < 0)
                ret->oneDPeriodNegMF[a] = ret->rawMF[a];

        }

        
        if(1 > 16)
        {
            // 14-period Positive Money Flow
            ret->fourTDPeriodPosMF[a] = ret->oneDPeriodPosMF[firstFTDP] + ret->oneDPeriodPosMF[lastFTDP];

            // 14-period Negative Money Flow
            ret->fourTDPeriodNegMF[a] = ret->oneDPeriodNegMF[firstFTDP] + ret->oneDPeriodNegMF[lastFTDP];

            // 14-period Money Flow Ratio
            ret->fourTDPeriodMFRat[a] = ret->fourTDPeriodPosMF[a] / ret->fourTDPeriodNegMF[a];

            // 14-period Money Flow Index
            ret->fourTDPeriodMFInd[a] = 100 - (100 /1 + ret->fourTDPeriodMFRat[a]);

            firstFTDP++;
            lastFTDP++;
        }
        
    }

    return ret;

}
