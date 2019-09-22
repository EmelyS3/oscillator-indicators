#ifndef CMF_H
#define CMF_H

#include <iostream>
#include <list>

struct CsvValues
{
   double *h;
   double *c;
   double *l;
   double *v;
   int maxIndx;
};

typedef struct _RetValues
{
    double *mfMultipler;
    double *nPeriods;
    double *mfVolume;
    int retCode;
} RetValues, *P_ARRAY_RETVALUES;





class CMF
{

public:

    CMF();

    P_ARRAY_RETVALUES Calculate(double *high,
                       double *low,
                       double *close,
                       double *volume,
                       int maxPeriod);

    double *DivLists(double colum1[],
                    double colum2[],
                    int maxPeriod);
};

#endif // CMF_H
