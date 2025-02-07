#include "Manager.h"
#include "Operator.h"
#include "Asistent.h"

#include <list>
#include <fstream>
#pragma once

void specificA(list<Angajat*>);                           //cauta un obiect specific
list<Angajat*>::iterator getIterator(list<Angajat*>&);  //gaseste iterator pentru ID-ul selectat
void createA(list<Angajat*>&);                            //creeaza un obiect nou de pus in lista
void removeA(list<Angajat*>&);                            //sterge un obiect din lista
void changeNume(list<Angajat*>&);                         //schimba numele
void loadingAngajati(list<Angajat*>&);                            //incarca angajatii din CSV
void meniu_angajati(list<Angajat*>&);                      //printeaza meniul de angajati
