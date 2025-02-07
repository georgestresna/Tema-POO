#include "Disc.h"

Disc::Disc(int a, string b, int c, double d, string e, string f, string g, string h)
    :Produse(a, b, c, d), casa_discuri(e), data_vanzare(f), trupa(g), nume_album(h)
{}

void Disc::afisare() const
{
    cout<<"Disc: ";
        Produse::afisare();
    cout<<"Caracteristici proprii: "<<casa_discuri<<" "<<data_vanzare<<" "<<trupa<<" "<<nume_album<<endl;
}

double Disc::getPret()const{
    return Produse::getPret() + 5;
}
