#include "functiiProduse.h"

void specificP(list<Produse*>& vec)
{
    list<Produse*>::iterator it = getIteratorP(vec);

    try
    {
        if (it != vec.end())    (*it)->afisare();
        else    throw std::runtime_error("Nu a fost gasit produsul.");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }
}

void loadingProduse(list<Produse*>& vec)
{
    ifstream f("dataProduse.csv");
    string buff;
    int i=0;

    while(!f.eof())
    {
        getline(f, buff);
        i++;
    }
    f.seekg (0, ios::beg);


    int auxID, auxStoc, type;
    string auxNume, auxCuloare, auxMarca;
    double auxPret;

    string auxCasaDiscuri, auxDataVanzare, auxTrupa, auxNumeAlbum;
    bool auxMint;
    int auxCoefRaritate;

    int vI=0, dI=0, dvI=0;

    //Populez vector
    for(int j=0; j<i; j++)
    {
        type = 3;
        if(j<7) type =2;
        if(j<3) type = 1;

        //3 -4 - 3
        getline(f, buff);
        stringstream ss;
        string aux;
        ss.str(buff);

        //ID
        getline( ss, aux, ',' );
        auxID=stoi(aux);
        //NUME produs
        getline( ss, aux, ',' );
        auxNume = aux;
        //stoc
        getline( ss, aux, ',' );
        auxStoc = stoi(aux);
        //pret
        getline( ss, aux, ',' );
        auxPret = stod(aux);
        //vestimentar
        //culoare
        getline( ss, aux, ',' );
        auxCuloare = aux;
        //marca
        getline( ss, aux, ',' );
        auxMarca = aux;
        //disc
        //casadiscuri
        getline( ss, aux, ',' );
        auxCasaDiscuri = aux;
        //datavanzare
        getline( ss, aux, ',' );
        auxDataVanzare = aux;
        //trupa
        getline( ss, aux, ',' );
        auxTrupa = aux;
        //nume album
        getline( ss, aux, ',' );
        auxNumeAlbum = aux;
        //disc vintage
        //mint album
        getline( ss, aux, ',' );
        if(aux=="0") auxMint=0;
        else auxMint =1;
        //coef album
        getline( ss, aux, ',' );
        if(aux != "")   auxCoefRaritate = stoi(aux);


        try
        {
            switch(type)
            {
            case 1:
                //Vestimentar
                vec.push_back(new Vestimentar(auxID, auxNume, auxStoc, auxPret, auxCuloare, auxMarca));
                vI++;
                break;
            case 2:
                //Disc
                vec.push_back(new Disc(auxID, auxNume, auxStoc, auxPret, auxCasaDiscuri, auxDataVanzare, auxTrupa, auxNumeAlbum));
                dI++;
                break;
            case 3:
                //Disc_vintage
                vec.push_back(new Disc_vintage(auxID, auxNume, auxStoc, auxPret, auxCasaDiscuri, auxDataVanzare, auxTrupa, auxNumeAlbum, auxMint, auxCoefRaritate));
                dvI++;
                break;
            default:
                throw std::runtime_error("Aici throw eerror");
                break;
            }
        }
        catch(const std::exception& e)
        {
            cerr << "Eroare:\t "<< e.what()<<endl;
        }
    }
    //cout<<mI<<" "<<oI<<" "<< aI;
    try
    {
        if(vI < 2 || dI < 2 || dvI < 2)   throw std::runtime_error("Nu este destul produse pa raft");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }

    f.close();
}

void createP(list<Produse*>& vec)
{
    int type;//1m, 2o, 3a
    cout<<"\n\nTipul produsului nou: 1(Vestimentar), 2(Disc), 3(Disc Vintage)\n\n";
    cin>>type;
    Produse* aux = nullptr;

    int auxID, auxStoc;
    string auxNume, auxCuloare, auxMarca;
    double auxPret;

    string auxCasaDiscuri, auxDataVanzare, auxTrupa, auxNumeAlbum;
    bool auxMint;
    int auxCoefRaritate;

    cout<<"Adauga ID, Nume, Buc Stoc, Pret: ";
    cin>>auxID>> auxNume>> auxStoc>> auxPret;

    try
    {
        switch(type)
        {
        case 1:
            cout<<"Adauga Culoarea, Marca: \n";
            cin>>auxCuloare>>auxMarca;
            vec.push_back(new Vestimentar(auxID, auxNume, auxStoc, auxPret, auxCuloare, auxMarca));
            break;
        case 2:
            cout<<"\n Adauga CasaDiscuri, DataVanzare, Trupa, NumeAlbum: \n";
            cin>>auxCasaDiscuri>>auxDataVanzare>>auxTrupa>>auxNumeAlbum;
            vec.push_back(new Disc(auxID, auxNume, auxStoc, auxPret, auxCasaDiscuri, auxDataVanzare, auxTrupa, auxNumeAlbum));
            break;
        case 3:
            cout<<"\n Adauga CasaDiscuri, DataVanzare, Trupa, NumeAlbum, Este mint?(0/1), Coeficient Raritate: \n";
            cin>>auxCasaDiscuri>>auxDataVanzare>>auxTrupa>>auxNumeAlbum>>auxMint>>auxCoefRaritate;
            vec.push_back(new Disc_vintage(auxID, auxNume, auxStoc, auxPret, auxCasaDiscuri, auxDataVanzare, auxTrupa, auxNumeAlbum, auxMint, auxCoefRaritate));
            break;
        default:
            throw std::runtime_error("Type invalid\n");
            break;
        }
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }

    vec.back()->afisare();
}

void removeP(list<Produse*>& vec)
{
    list<Produse*>::iterator it = getIteratorP(vec);

    try
    {
        if (it != vec.end())
        {
            cout << "Produs gasit: ";
            (*it)->afisare(); // Displaying the one found before removal

            vec.erase(it); // Properly remove the Angajat from list using erase
            cout << "Produsul s-a sters cu succes." << endl; // Success message
        }
        else    throw std::runtime_error("Nu a fost gasit produsul.");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }
}

list<Produse*>::iterator getIteratorP(list<Produse*>& vec)
{
    int ID;
    cout << "ID produs cautat: ";
    cin >> ID;

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if ((*it)->getID() == ID)   return it;
    }
    return vec.end();
}

void changeP(list<Produse*>& vec)
{
    list<Produse*>::iterator it = getIteratorP(vec);
    try
    {
        if (it != vec.end())
        {
            int stocNou = 0;
            cout<<"Stocul pt acest produs este: "<< (*it)->getStoc()<<" \n";
            cout << "Introduceti stoc nou: ";
            cin >> stocNou;

            (*it)->setStoc(stocNou);
            cout << "Stoc schimbat cu succes!" << endl;
        }
        else    throw std::runtime_error("Nu a fost gasit produsul.");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }
}

void meniu_produse(list<Produse*>& vec)
{
    cout<<"\n\n----------------Meniu produse-----------------------\n\n";
    int choice;
    cout<<"Alege operatiune: \n\t1.Agauga produs\n\t2.Sterge produs\n\t3.Modificare stoc produs";
    cout<<"\n\t4.Afisare detalii produs\n\t5.Afisare toate produsele\n";
    cin>>choice;
    cout<<"\n\n--------------------------------------------------------\n\n";

    switch(choice)
    {
    case 1:
        createP(vec);
        break;
    case 2:
        removeP(vec);
        break;
    case 3:
        changeP(vec);
        break;
    case 4:
        specificP(vec);
        break;
    case 5:
        for (const auto& produs : vec)
        {
            produs->afisare();    // Apelăm funcția de afișare pentru fiecare angajat
            cout<<"\n";
        }
        break;
    default:
        break;
    }
}

