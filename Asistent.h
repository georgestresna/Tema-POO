#include "Angajat.h"

class Asistent: public Angajat
{
public:
    Asistent(int, string, string, string, string);

    void afisare() const override;
    double getSalariu() const override;
};
