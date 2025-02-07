#include "Disc_vintage.h"

Disc_vintage::Disc_vintage(int a, string b, int c, double d, string e, string f, string g, string h, bool i, int j)
    :Disc(a, b, c, d, e, f, g, h), mint(i), coef_raritate(j)
{
    if(coef_raritate < 1 || coef_raritate > 5)  cerr<<"Raritate gresta";
}

void Disc_vintage::afisare() const
{
    cout<<"Disc vintage: ";
        Disc::afisare();
    cout<<"Caracteristici vintage: "<<mint<<" "<<coef_raritate<<endl;
}

double Disc_vintage::getPret() const{
    return Disc::getPret() + (15 * coef_raritate);
}
