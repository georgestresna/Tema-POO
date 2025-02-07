#include "Operator.h"

Operator::Operator(int a, string b, string c, string d, string e)
    :Angajat(a, b, c, d, e)
{}

void Operator::afisare()const
{
    cout<<"OPERATOR: ";
    Angajat::afisare();
    cout<<Operator::getSalariu()<<" lei"<<endl;
}


double Operator::getSalariu() const
{
    double salariu =Angajat::getSalariu();

    int luna_nasterii = stoi(CNP.substr(3, 2));
    time_t current = time(NULL);
    struct tm *datetime = localtime(&current);
    if(luna_nasterii == datetime->tm_mon + 1)    salariu +=100;

    return salariu;
}

void Operator::addComision(double aux)
{
    comision +=aux;
}
