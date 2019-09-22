#include "percentageb.h"

PercentageB::PercentageB()
{

}


P_ARRAY_PBVAL PercentageB::PBCalc(double *price,
                        double *lBand,
                        double *uBand,
                        int nPeriods)
{
    //%B = (Price - Lower Band)/(Upper Band - Lower Band)

    P_ARRAY_PBVAL ret = (P_ARRAY_PBVAL) malloc(1 * sizeof(P_ARRAY_PBVAL));
    ret->result = (double *) malloc(nPeriods * sizeof(double *));

    for(int a = 0; a < nPeriods; a++)
    {
        ret->result[a] = (price[a] - lBand[a]) / (uBand[a] - lBand[a]);
    }

    return ret;
}
