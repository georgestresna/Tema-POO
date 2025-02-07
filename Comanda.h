#include "Vestimentar.h"
#include "Disc_vintage.h"
#include <vector>
#include <list>

class Comanda{
private:
    /*vector<Vestimentar> vV;
    vector<Disc*> dV;*/
    int durataSolutionare = 0, id;
    string dataPrimire = "";
    vector<int> vV, vD;

public:
    Comanda() = default;

    Comanda(vector<int>, vector<int>, string, list<Produse*>&, int);

    void afisare();
    string getDataPrimire();
    double getPret(list<Produse*>&);
    int getDurataSolutionare();
    vector<int> getVV();
    vector<int> getDV();

    //Comanda(const Comanda&);
    //Comanda& operator=(const Comanda&);
    ~Comanda();
};
