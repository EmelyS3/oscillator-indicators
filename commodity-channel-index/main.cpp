#include <QCoreApplication>
#include "../../csv-reader/csvreader.h"
#include "../../base/base.h"
#include "cci.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CsvReader csv;

    Base b;
    QList<double> h;
    QList<double> l;
    QList<double> o;
    QList<double> c;

    QList<int> col;

    // Open
    col.push_back(6);

    // High
    col.push_back(3);

    // Low
    col.push_back(4);

    // Close
    col.push_back(5);

    csv.reader("/home/opensylar/Downloads/moving/csv/cci.csv",
                col, &h, &l, &o, &c, NULL);

    double *arrayO = b.ListToArray(o);
    double *arrayC = b.ListToArray(c);
    double *arrayL = b.ListToArray(l);
    double *arrayH = b.ListToArray(h);


    CCI cci;
    P_ARRAY_CCIVAL ret = (P_ARRAY_CCIVAL) malloc(1*sizeof(P_ARRAY_CCIVAL));

    double *vals = (double *) malloc(5*sizeof(double *));

    vals[0] = 30;
    vals[1] = 25;
    vals[2] = 10;
    vals[3] = 2;
    vals[4] = 1;

    // double *av = cci.avg(vals, 4);

    ret = cci.CCICalc(arrayC, arrayH, arrayL, h.size());

    for(int i = 0; i <  h.size(); i++)
    {
        qDebug() << ret->tp[i];
        qDebug() << ret->sma20TP[i];
        qDebug() << "sma20CCI:: " << ret->sma20CCI[i];
        qDebug() << "sma20MD:: " << ret->sma20MD[i] << "\r\n";
    }

    return a.exec();
}
