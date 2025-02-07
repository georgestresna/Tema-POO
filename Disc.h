#include "Produse.h"
#pragma once
class Disc: public Produse{
protected:
    string casa_discuri = "";
    string data_vanzare = "";
    string trupa = "";
    string nume_album = "";
public:
    Disc() = default;
    Disc(int, string, int, double, string, string, string, string);

    void afisare() const override;
    ~Disc() = default;
    double getPret() const override;
};
