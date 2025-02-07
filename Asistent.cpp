#include "Asistent.h"

Asistent::Asistent(int a, string b, string c, string d, string e)
    :Angajat(a, b, c, d, e)
{}

void Asistent::afisare()const
{
    cout<<"ASISTENT: ";
    Angajat::afisare();
    cout<<Asistent::getSalariu()<<" lei"<<endl;
}

double Asistent::getSalariu() const
{
    double salariu =Angajat::getSalariu() * 0.75;

    int luna_nasterii = stoi(CNP.substr(3, 2));
    time_t current = time(NULL);
    struct tm *datetime = localtime(&current);
    if(luna_nasterii == datetime->tm_mon + 1)    salariu +=100;

    return salariu;
}

/*
În afară de manager, fiecare angajat, de ziua lui,
primește bonus de 100 RON care se adaugă la salariul din acea lună.
*/
