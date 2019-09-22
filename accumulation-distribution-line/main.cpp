#include "adl.h"
#include "../../csv-reader/csvreader.h"
#include "../../base/base.h"

#ifdef TESTING


#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ADL adl;
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

    double *arrayH = b.ListToArray(h);
    double *arrayL = b.ListToArray(l);
    double *arrayC = b.ListToArray(c);
    double *arrayV = b.ListToArray(v);

    P_ARRAY_ADLVALUES retAdl = adl.Calculate(arrayH, arrayL, arrayC, arrayV, h.size());

    for(int e = 0; e < h.size(); e++)
    {
        std::cout << "Mult:: " << retAdl->mFMultipler[e] << std::endl;
        std::cout << "mfValue:: " << retAdl->mFValue[e] << std::endl;
        std::cout << "aDLine:: " << retAdl->aDLine[e] << std::endl << std::endl;
    }


    return a.exec();
}

#endif
