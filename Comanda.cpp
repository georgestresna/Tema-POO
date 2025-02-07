#include "Comanda.h"

Comanda::Comanda(vector<int> auxV, vector<int> auxD, string auxData, list<Produse*>& vec, int auxID):dataPrimire(auxData), vV(auxV), vD(auxD), id(auxID)
{
    double pretComanda = 0;
    if(auxV.size() > 3 && auxD.size() > 5)   throw std::runtime_error("Prea multe obiecte");

    //vV = auxV;
    for(const int ID : vV)
    {
        //cout<<id<<" ";
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            if ((*it)->getID() == ID)   pretComanda += (*it)->getPretInit();
        }
    }
    //vD = auxD;
    for(const int ID : vD)
    {
        //cout<<id<<" ";
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            if ((*it)->getID() == ID)   pretComanda += (*it)->getPretInit();
        }
    }

    //vestimentar = 10s; disc = 7s
    durataSolutionare = (vV.size() * 10) + (vD.size() * 7);
    if(pretComanda < 100)   throw std::runtime_error("Pret mai mic de 100lei: " + to_string(pretComanda));
}

Comanda::~Comanda()
{
    vV.clear();
    vD.clear();
}

void Comanda::afisare()
{
    cout<<"ID: "<<id<<"\n"<<vV.size()<<" Art. Vestimentare: ";
    for (auto it = vV.begin(); it != vV.end(); ++it) cout<<*it<<" ";
    cout<<endl;

    cout<<vD.size()<<" Discuri: ";
    for (auto it = vD.begin(); it != vD.end(); ++it) cout<<*it<<" ";
    cout<<endl<<"Primita la data: "<<dataPrimire<<"; Durata solutionare: "<<durataSolutionare;
    cout<<endl;
}

string Comanda::getDataPrimire(){
    return dataPrimire;
}

double Comanda::getPret(list<Produse*>& vec){
    double pretComanda = 0;
    for(const int ID : vV)  for (auto it = vec.begin(); it != vec.end(); ++it)      if ((*it)->getID() == ID)   pretComanda += (*it)->getPret();
    for(const int ID : vD)  for (auto it = vec.begin(); it != vec.end(); ++it)      if ((*it)->getID() == ID)   pretComanda += (*it)->getPret();
    return pretComanda;
}

int Comanda::getDurataSolutionare(){
    return durataSolutionare;
}

vector<int> Comanda::getVV(){
    return vV;
}

vector<int> Comanda::getDV(){
    return vD;
}
