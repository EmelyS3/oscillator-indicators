#include <QCoreApplication>
#include "aroon.h"
#include "../../csv-reader/csvreader.h"
#include "../../base/base.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Aroon e;
    CsvReader csv;

    QList<int> colums;

    // High
    colums.push_back(3);

    // Low
    colums.push_back(4);

    // Close
    colums.push_back(5);

    // Volume
    colums.push_back(7);

    QList<double> h;
    QList<double> l;
    QList<double> c;
    QList<double> v;

    csv.reader("/home/opensylar/Downloads/moving/csv/adl.csv", colums, &h, &l, &c, &v);

    Base b;

    double *arrayUp = b.ListToArray(h);
    double *arrayDown = b.ListToArray(l);

    P_ARRAY_AROONVALUES ret = e.AroonCalc(arrayUp, arrayDown, 25);

    for(int o = 0; o < 25; o++)
    {
        std::cout << ret->up[o] << std::endl;
    }

    return a.exec();
}
