#include "Angajat.h"

class Manager: public Angajat{
public:
    Manager(int, string, string, string, string);

    void afisare() const override;
    double getSalariu() const override;
};
