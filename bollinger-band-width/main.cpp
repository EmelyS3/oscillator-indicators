#include <QCoreApplication>
#include "bollingerbandwidth.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BollingerBandWidth bbw;
    int nPeriods = 20;
    double *midBand = (double *) malloc(nPeriods * sizeof(double *));
    double *dwnBand = (double *) malloc(nPeriods * sizeof(double *));
    double *uppBand =  (double *) malloc(nPeriods * sizeof(double *));

    bbw.BBWCalc(uppBand, dwnBand, midBand);

    return a.exec();
}
