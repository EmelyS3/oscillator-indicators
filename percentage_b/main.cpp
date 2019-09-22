#include <QCoreApplication>
#include "percentageb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PercentageB pb;
    int periods = 20;
    double *prices = (double *) malloc(periods * sizeof(double *));
    double *lowB = (double *) malloc(periods * sizeof(double *));
    double *upperB = (double *) malloc(periods * sizeof(double *));


    P_ARRAY_PBVAL ret = pb.PBCalc(prices, lowB, upperB, periods);

    for(int a = 0; a < periods; a++)
    {
        std::cout << ret->result[a] << std::endl;
    }

    return a.exec();
}
