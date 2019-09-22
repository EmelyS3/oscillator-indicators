#include <QCoreApplication>
#include <QDebug>
#include "mfi.h"
#include "../../csv-reader/csvreader.h"
#include "../../base/base.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CsvReader csv;
    Base b;
    QList<double> v;
    QList<double> h;
    QList<double> l;
    QList<double> c;

    QList<int> col;    
    col.push_back(2);
    col.push_back(3);
    col.push_back(4);
    col.push_back(5);
    col.push_back(8);

    csv.reader("/home/opensylar/Downloads/moving/csv/mfi.csv",
               col, &h, &l, &c, &v);


    double *arrayVols = b.ListToArray(v);
    double *arrayHigh = b.ListToArray(h);
    double *arrayLow = b.ListToArray(l);
    double *arrayClose = b.ListToArray(c);

    MFI mfi;

    P_ARRAY_CCIVAL ret = (P_ARRAY_CCIVAL) malloc(1* sizeof(P_ARRAY_CCIVAL));

    ret = mfi.MFICalc(arrayHigh, arrayLow,
                arrayClose,
                arrayVols,
                v.size());

    for(int i = 0; i < v.size(); i++)
    {
        qDebug() << ret->rawMF[i];
    }

    return a.exec();
}
