#include <QCoreApplication>
#include "../../base/base.h"
#include "aroonoscillator.h"

#define MAX_ITER 25

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<double> h;
    QList<double> l;

    Base b;
    int maxValue = 25;
    int alta = 0;
    int baja = 100;

    for(int a = 0; a <= maxValue;
        alta = alta + 4,
        baja = baja - 4,
        a++)
    {
        h.push_back(baja);
        l.push_back(alta);
    }

    double *arrayUp = b.ListToArray(h);
    double *arrayDown = b.ListToArray(l);

    AroonOscillator oscillator;

    P_ARRAY_AROONOSCILLATORVAL amen = oscillator.AroonOscillatorCalc(arrayUp, arrayDown, MAX_ITER);

    for(int e = 0; e < MAX_ITER; e++)
    {
        std::cout << amen->result[e] << std::endl;
    }


    return a.exec();
}
