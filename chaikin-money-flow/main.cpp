#include "cmf.h"
#include <iostream>
#define MAX_RESULT 20

#ifdef TESTING

#include <QFile>

CsvValues fillValues(QString path)
{

    double *h;
    double *l;
    double *c;
    double *v;
    CsvValues ret;

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        return ret;
    }

    QList<QByteArray> wordList;
    std::list<std::string> date;
    std::list<double> high;
    std::list<double> low;
    std::list<double> close;
    std::list<double> volume;
    QByteArray line;

    while (!file.atEnd())
    {
        line = file.readLine();
        wordList = line.split(',');

        date.push_back(wordList.at(2).toStdString());

        if(wordList.at(3).toDouble() > 0)
            high.push_back(wordList.at(3).toDouble());

        if(wordList.at(4).toDouble() > 0)
            low.push_back(wordList.at(4).toDouble());

        if(wordList.at(5).toDouble() > 0)
            close.push_back(wordList.at(5).toDouble());

        if(wordList.at(7).toDouble() > 0)
            volume.push_back(wordList.at(7).toDouble());
    }    

    h = (double *) malloc(high.size() * sizeof(double *));
    l = (double *) malloc(low.size() * sizeof(double *));
    c = (double *) malloc(close.size() * sizeof(double *));
    v = (double *) malloc(volume.size() * sizeof(double *));
    auto itH = high.begin();
    auto itL = low.begin();
    auto itC = close.begin();
    auto itV = volume.begin();
    int i = 0;

    for (; itH != high.end(); ++itH, ++itC, ++itL, ++itC, ++itV)
    {
        h[i] = *itH;
        l[i] = *itL;
        c[i] = *itC;
        v[i] = *itV;
        i++;
    }

    ret.c = c;
    ret.h = h;
    ret.l = l;
    ret.v = v;
    ret.maxIndx = i;

    return ret;

}


int main()
{

    CsvValues csvVals = fillValues("/home/opensylar/Downloads/moving/csv/cs-cmf.csv");

    CMF *chaikin = new CMF();
    P_ARRAY_RETVALUES retCMF;

    retCMF = chaikin->Calculate(csvVals.h, csvVals.l,
                        csvVals.c, csvVals.v, MAX_RESULT);

    for(int i = 0; i <= MAX_RESULT; i++)
    {
        std::cout << "[+] MULTS:: " << retCMF->mfMultipler[i] << std::endl;
        std::cout << "[+] Vols:: " << retCMF->mfVolume[i] << std::endl;
        std::cout << "[+] Periods:: " << retCMF->nPeriods[i] << std::endl << std::endl;
    }

    return 0;
}

#endif


P_ARRAY_RETVALUES cmf_oscillator(double *h, double *l,
                       double *c, double *v,
                       int periods)
{

    CMF *chaikin = new CMF();
    chaikin->Calculate(h, l, c, v, periods);
    RetValues *ret = (RetValues *) malloc(10);
    return ret;

}


extern "C"
{
    extern P_ARRAY_RETVALUES cffi_cmf_oscillator(double *h, double *l, double *c, double *v, int periods)
    {
        return cmf_oscillator(h, l, c, v, periods);
    }
}

