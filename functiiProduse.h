#include "Vestimentar.h"
#include "Disc_vintage.h"

#include <list>
#include <fstream>
#pragma once

void meniu_produse(list<Produse*>&);
void loadingProduse(list<Produse*>&);
void createP(list<Produse*>&);
void removeP(list<Produse*>&);
list<Produse*>::iterator getIteratorP(list<Produse*>&);
void specificP(list<Produse*>&);
void changeP(list<Produse*>&);
