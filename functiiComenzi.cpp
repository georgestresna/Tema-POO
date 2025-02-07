#include "functiiComenzi.h"
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include <unistd.h>

void afisareComenzi(queue<Comanda> q, list<Produse*>& vec2)
{
    cout<<"\n\n--------------------Coada comenzi-----------------------\n\n";
    while (!q.empty())
    {
        q.front().afisare();    //cout<<endl;
        cout<<"Pret total comanda: "<<q.front().getPret(vec2);
        cout<<endl<<endl;
        q.pop();
    }

    cout<<"\n\n--------------------------------------------------------\n\n";
}

void loadingComenzi(queue<Comanda>& vec, list<Produse*>& vec2)
{
    ifstream f("comenzi.txt");
    string buff;
    int i=0;

    while(!f.eof())
    {
        getline(f, buff);
        i++;
    }
    f.seekg (0, ios::beg);

    vector<int> auxV, auxD;
    string auxData="";
    vector<Comanda> unordered;
    int auxID;

    for(int j=0; j<i; j++)
    {
        int iV=0, iD=0;
        auxV.clear();
        auxD.clear();
        getline(f, buff);

        stringstream ss;
        ss.str(buff);
        string aux;

        getline( ss, aux, ' ' );
        auxID = stoi(aux);

        getline( ss, aux, ' ' );
        iV=stoi(aux);
        for(int k=0; k<iV; k++)
        {
            getline( ss, aux, ' ' );
            auxV.push_back(stoi(aux));
        }

        getline( ss, aux, ' ' );
        iD=stoi(aux);
        for(int k=0; k<iD; k++)
        {
            getline( ss, aux, ' ' );
            auxD.push_back(stoi(aux));
        }

        getline( ss, auxData, ' ' );

        try
        {
            unordered.push_back(Comanda(auxV, auxD, auxData, vec2, auxID));
        }
        catch(const std::exception& e)
        {
            cerr << "Eroare:\t "<< e.what()<<endl;
        }
    }

    sort(unordered.begin(), unordered.end(), [](Comanda& a, Comanda& b)
    {
        return a.getDataPrimire() < b.getDataPrimire();
    });
    /*for (auto& item : unordered) {
        item.afisare(); // Call afisare() for each object
    }*/
    for(auto& item: unordered) vec.push(item);
    unordered.clear();
}

list<Produse*>::iterator getIteratorProd(list<Produse*>& vec, int ID)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if ((*it)->getID() == ID)   return it;
    }
    return vec.end();
}

void modifyStoc(Comanda com, list<Produse*>& vec2)
{
    vector<int> vV = com.getVV();
    vector<int> dV = com.getDV();

    for(int itemV : vV)
    {
        list<Produse*>::iterator it = getIteratorProd(vec2, itemV);
        int success = (*it)->takeItem();
        if(!success)    throw std::runtime_error("Eroare nu mai este stoc pentru aces produs!");
    }
    for(int itemD : dV)
    {
        list<Produse*>::iterator it = getIteratorProd(vec2, itemD);
        int success = (*it)->takeItem();
        if(!success)    throw std::runtime_error("Eroare nu mai este stoc pentru aces produs!");
    }
}

void beginProcess(list<Angajat*>& vec, list<Produse*>& vec2, queue<Comanda>& vec3, int* mC)
{
    ///im cooked

    ///1. scos toti operatorii (primesc si 0.5% din fiecare comanda procesata)
    vector<Operator*> pOperator;

    for (auto& angajat : vec)
    {
        if (Operator* op = dynamic_cast<Operator*>(angajat))
        {
            pOperator.push_back(op);
        }
    }

    //vector<double> comision(pOperator.size(),0);
    vector<vector<int>> ocupat(pOperator.size(), vector<int>(3, 0));
    vector<int> comenziQueue(pOperator.size(),0);
    ///pentru rapoarte
    vector<int> mostComenzi(pOperator.size(),0);

    while(1)
    {
        system("cls");
        cout<<"\n\n----------------Live Prelucrare-----------------------\n\n";

        for( int i = 0; i < comenziQueue.size(); i++)
        {
            for(int j = 0; j < 3; j++)
                if(ocupat[i][0])
                {
                    ocupat[i][j]--;
                    if(!ocupat[i][j])
                    {
                        comenziQueue[i]--;
                        ///rearanjare
                        for(int k = j; k < 2; k++)
                        {
                            ocupat[i][k] = ocupat[i][k+1];
                        }
                        ocupat[i][2] = 0;
                    }
                    break;
                }
        }

        while(!vec3.empty())
        {
            int minComenzi = 4;
            ///find minimum comenzi
            for(int comanda : comenziQueue)     if(comanda < minComenzi)    minComenzi = comanda;

            if(minComenzi < 3)
            {
                ///pun comanda la cine are cele mai putine
                for(int i=0; i<comenziQueue.size(); i++)
                {
                    if(minComenzi == comenziQueue[i])
                    {
                        try
                        {
                            Comanda aux = vec3.front();
                            modifyStoc(aux, vec2);
                            pOperator[i]->addComision(aux.getPret(vec2));
                            ocupat[i][comenziQueue[i]] = aux.getDurataSolutionare();
                            //cout<<comenziQueue[i]-1;
                            //exit(1);
                            ///de sters itemele din comanda din stoc
                            comenziQueue[i]++;
                            mostComenzi[i]++;       ///raport
                        }
                        catch(const std::exception& e)
                        {
                            cerr << "Eroare:\t "<< e.what()<<endl;
                        }
                        vec3.pop();
                        ///sa dau output ca comanda x a fost asignata lui y durata z secunde
                        break;
                    }
                }
            }
            else
            {
                cout<<"Toti operatorii sunt ocupati momentan, comenzile din coada vor fi asignate imedit ce un operator este liber\n\n";
                break;
            }
        }

        for(int i = 0; i < comenziQueue.size(); i++)
        {
            cout<<pOperator[i]->getID()<<"\tSalariu curent: "<<pOperator[i]->getSalariu()<<"\tNr. Comenzi.: "<<comenziQueue[i]<<endl;
            cout<<"Coada angajatului: ["<<ocupat[i][0]<<"] "<<"["<<ocupat[i][1]<<"] "<<"["<<ocupat[i][2]<<"]"<<endl<<endl;
        }

        cout<<"\n\n--------------------------------------------------------\n\n";

        ///a se comenta pentru testare rapida
        sleep(1);

        int cont = 0;
        for(int i = 0; i < comenziQueue.size(); i++) if(comenziQueue[i]) cont=1;
        if(!cont)
        {
            cout<<"\n\n--------------------------------------------------------\n\n";
            cout<<"Toate comenzile au fost procesate";
            cout<<"\n\n--------------------------------------------------------\n\n";
            break;
        }
    }
    ///prelucrare data pt rapoarte
    int indexInt=-1, maxComenzi = -1;
    for(int i=0; i< mostComenzi.size(); i++)    if(mostComenzi[i] > maxComenzi)
        {
            indexInt=i;
            maxComenzi = mostComenzi[i];
        }
    *mC = pOperator[indexInt]->getID();
    //cout<<pOperator[indexInt]->getID();

    //cel mai mare comision top 3
    //top3 ang cu c m mare salariu in general

}

void meniu_comenzi(list<Angajat*>& vec, list<Produse*>& vec2, queue<Comanda>& vec3, int* mC)
{
    cout<<"\n\n----------------Meniu comenzi-----------------------\n\n";
    int choice;
    cout<<"Alege operatiune: \n\t1.Vezi lista comenzi\n\t2.Deruleaza pana se goleste lista\n";
    cin>>choice;
    cout<<"\n\n--------------------------------------------------------\n\n";

    switch(choice)
    {
    case 1:
        afisareComenzi(vec3, vec2);
        break;
    case 2:
        beginProcess(vec, vec2, vec3, mC);
        break;
    default:
        break;
    }
}

void rapoarte(int* mC, list<Angajat*> vec)
{
    cout<<"Rapoarte\n";
    list<Angajat*>::iterator it = vec.begin();
    if(*mC)
    {
        cout<<"Angajatul cu ID: "<<*mC<<" a procesat cele mai multe comenzi!\n\n";
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            if ((*it)->getID() == *mC)
            {
                (*it)->afisare();
                break;
            }
        }
    }
    else cout<<"Nu au fost procesate comenzi!";


    list<Angajat*> vecAux;
    vec.sort([](const Angajat* a, const Angajat* b)
    {
        return a->getSalariu() > b->getSalariu();
    });

    for(int i=0; i<3; i++)
    {
        vecAux.push_back(vec.front());
        vec.pop_front();
    }

    vecAux.sort([](const Angajat* a, const Angajat* b)
    {
        return a->getNume() < b->getNume();
    });

    // Display sorted list
    cout<<"\n\n--------------------------Top 3 salarii-------------------------------\n\n";
    for (auto angajat : vecAux)
    {
        angajat->afisare();
    }

    ///scriere in .csv
    try
    {
        ofstream out("raport.csv");
        string row = "Angajatul care a procesat cele mai multe comenzi,ID: " + to_string(*mC) + "; Nume: " + (*it)->getNume() + "; Salariu: " + to_string((*it)->getSalariu()) + ",\n";
        out<<row;
        row = "Neimplementat,\n";
        out<<row;
        row = "Top 3 angajati cu cel mai mare salariu in aceasta luna,";
        for (auto angajat : vecAux)
        {
            row += "ID: " + to_string(angajat->getID()) + "; Nume: " + angajat->getNume() + "; Salariu: " + to_string(angajat->getSalariu());
            row+=",";
        }
        row+="\n";
        out<<row;
        out.close();
        cout<<"\n\n-----------Fisierul raport.csv a fost creeat cu success!----------\n\n";
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }

    vecAux.clear();
}
