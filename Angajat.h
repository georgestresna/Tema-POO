#include <iostream>
#include <string.h>
#include <ctime>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

class Angajat{
protected:
    int ID = -1;
    string nume = "";
    string prenume = "";
    string CNP= "";
    string data_angajare="";
    double comision = 0;
public:
    Angajat() = default;
    virtual ~Angajat() = default;
    Angajat(int, string, string, string, string);
    int getID();
    int getComision();
    string getNume() const;

    virtual void afisare() const;
    virtual double getSalariu() const;
    virtual void setNume(const string);
    //virtual void addComision(double) const=0;
    virtual void addComision(double) {}
};
