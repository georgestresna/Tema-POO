#include "Angajat.h"

class Operator: public Angajat{
public:
    Operator(int, string, string, string, string);

    void afisare() const override;
    double getSalariu() const override;
    void addComision(double) override;
};
