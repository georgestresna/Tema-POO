#include "Disc.h"
#pragma once
class Disc_vintage: public Disc{
private:
    bool mint = false;
    int coef_raritate = 0;
public:
    Disc_vintage() = default;
    Disc_vintage(int, string, int, double, string, string, string, string, bool, int);
    void afisare() const;
    ~Disc_vintage() = default;
    double getPret() const override;
};
