#include "Manager.h"

Manager::Manager(int a, string b, string c, string d, string e)
    :Angajat(a, b, c, d, e)
{}

void Manager::afisare()const
{
    cout<<"MANAGER: ";
    Angajat::afisare();
    cout<<Manager::getSalariu()<<" lei"<<endl;
}

double Manager::getSalariu() const
{
    double salariu =Angajat::getSalariu() * 1.25;

    return salariu;
}

