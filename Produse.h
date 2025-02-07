#include <iostream>
#include <string.h>
#include <ctime>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

class Produse{
protected:
    int id = 0;
    string denumire = "";
    int nr_stoc = 0;
    double pret =0;
public:
    Produse() = default;
    Produse(int, string, int, double);
    virtual ~Produse() = default;

    double getPretInit();
    virtual double getPret() const;
    virtual void afisare() const;
    int getID();
    int takeItem();
    int getStoc();
    virtual void setStoc(const int);
};
