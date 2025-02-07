#include "Produse.h"
#pragma once
class Vestimentar: public Produse{
    string culoare = "";
    string marca = "";
public:
    Vestimentar() = default;

    Vestimentar(int, string, int, double, string, string);
    void afisare() const override;
    double getPret() const override;
    ~Vestimentar() = default;
};
