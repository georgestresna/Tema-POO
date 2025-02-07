#include "Produse.h"

Produse::Produse(int a, string b, int c, double d)
    :id(a), denumire(b), nr_stoc(c), pret(d)
{}

void Produse::afisare() const
{
    cout<<"Caracteristici default: "<<id<<" "<<denumire<<" "<<nr_stoc<<" "<<pret<<endl;
}

double Produse::getPret() const
{
    return pret;
}

int Produse::getID(){
    return id;
}

void Produse::setStoc(const int new_stoc)
{
    nr_stoc = new_stoc;
}

double Produse::getPretInit(){
    return pret;
}

int Produse::takeItem(){
    if(nr_stoc) nr_stoc--;
    else        return 0;
    return 1;
}

int Produse::getStoc(){
    return nr_stoc;
}
