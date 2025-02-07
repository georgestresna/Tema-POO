#include "functiiAngajati.h"
#include "functiiProduse.h"
#include "functiiComenzi.h"

//#include <list>
//#include <fstream>
//#pragma once


void meniu(list<Angajat*>& vec, list<Produse*>& vec2, queue<Comanda>& vec3, int* mC)
{
    cout<<"\n\n----------------Meniu principal-----------------------\n\n";
    int choice=0;
    cout<<"Alege operatiune: \n";
    cout<<"\t1.Gestionare angajati\n\t2.Gestionare stoc\n\t3.Procesoare comenzi\n\t4.Rapoarte\n";
    cin>>choice;
    cout<<"\n\n--------------------------------------------------------\n\n";
    switch(choice)
    {
    case 1:
        meniu_angajati(vec);
        break;
    case 2:
        meniu_produse(vec2);
        break;
    case 3:
        meniu_comenzi(vec, vec2, vec3, mC);
        break;
    case 4:
        rapoarte(mC, vec);
        break;
    default:
        cerr<<"NU s a ales nicio opt corecta";
        break;
    }
}


int main()
{
    cout<<"\n\n----------------Initializare Aplicatie-----------------------\n\n";

    cout<<"Loading existing angajati...\n";
    list<Angajat*> vec;
    loadingAngajati(vec);
    cout<<"Existing angajati loaded!\n";


    cout<<"Loading existing Produse...\n";
    list<Produse*> vec2;
    loadingProduse(vec2);
    cout<<"Existing produse loaded!\n";

    cout<<"Loading existing Comenzi...\n";
    queue<Comanda> vec3;
    loadingComenzi(vec3, vec2);
    cout<<"Existing comenzi loaded!\n";

    cout<<"Initialising raport...\n";
    int mostComenzi = 0;
    vector<Angajat*> mostSalariu;
    cout<<"Raport initialised...\n";

    cout<<"\n\n----------------Sfarsit Initializare-----------------------\n\n";

    //Display interfata
    meniu(vec, vec2, vec3, &mostComenzi);
    while(1)
    {
        bool acord =false;
        cout<<"Se vrea reluare?(0 - Nu ; 1 - Da)?: ";
        cin>>acord;
        if(acord)   meniu(vec, vec2, vec3, &mostComenzi);
        else break;
    }


    //reactualizare fisiere cu datele updatate
    return 0;
}
