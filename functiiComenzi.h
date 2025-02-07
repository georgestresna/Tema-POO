#include "Comanda.h"
#include "functiiAngajati.h"
//#include "functiiProduse.h"
#include <queue>

void loadingComenzi(queue<Comanda>&, list<Produse*>&);
void meniu_comenzi(list<Angajat*>&, list<Produse*>&, queue<Comanda>&, int*);
void afisareComenzi(queue<Comanda>, list<Produse*>&);
void beginProcess(queue<Comanda>&);

void rapoarte(int*, list<Angajat*>);
