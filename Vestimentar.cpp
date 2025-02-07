#include "Vestimentar.h"

Vestimentar::Vestimentar(int a, string b, int c, double d, string e, string f)
    :Produse(a, b, c, d), culoare(e), marca(f)
{}

void Vestimentar::afisare() const
{
    cout<<"Articol vestimentar: ";
    Produse::afisare();
    cout<<"Caracteristici proprii: "<<culoare<<" "<<marca<<endl;
}

double Vestimentar::getPret() const
{
    return Produse::getPret() + 20;
};
