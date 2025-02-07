#include "functiiAngajati.h"

void specificA(list<Angajat*> vec)
{
    list<Angajat*>::iterator it = getIterator(vec);

    try{
        if (it != vec.end())    (*it)->afisare();
    else    throw std::runtime_error("Nu a fost gasita persoana.");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }

}

list<Angajat*>::iterator getIterator(list<Angajat*>& vec)
{
    int ID;
    cout << "ID pers cautata: ";
    cin >> ID;

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if ((*it)->getID() == ID)   return it;
    }
    return vec.end();
}

void createA(list<Angajat*>& vec)
{
    int type;//1m, 2o, 3a
    cout<<"\n\nTipul angajatului nou: 1(manager), 2(operator), 3(Asistent)\n\n";
    cin>>type;
    Angajat* aux = nullptr;

    int aID;
    string anume, aprenume, aCNP;
    cout<<"Adauga ID, Nume, Prenume, CNP: ";
    cin>>aID>> anume>> aprenume>> aCNP;
    time_t now = time(nullptr);
    tm localTime = *localtime(&now);

    ostringstream dateStream;
    dateStream << put_time(&localTime, "%Y-%m-%d");
    string adata_angajare = dateStream.str();

    try
    {
        switch(type)
        {
        case 1:
            vec.push_back(new Manager(aID, anume, aprenume, aCNP, adata_angajare));
            break;
        case 2:
            vec.push_back(new Operator(aID, anume, aprenume, aCNP, adata_angajare));
            break;
        case 3:
            vec.push_back(new Asistent(aID, anume, aprenume, aCNP, adata_angajare));
            break;
        default:
            throw std::runtime_error("Type invalid");
            break;
        }
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what() << ". Angajat neAdaugat" <<endl;
    }

    vec.back()->afisare();
}

void removeA(list<Angajat*>& vec)
{
    list<Angajat*>::iterator it = getIterator(vec);


    try
    {
        if (it != vec.end())
        {
            cout << "Angajat gasit: ";
            (*it)->afisare();
            vec.erase(it);
            cout << "Angajat s-a sters cu succes." << endl;
        }
        else    throw std::runtime_error("Nu a fost gasita persoana.");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }

}

void changeNume(list<Angajat*>& vec)
{
    list<Angajat*>::iterator it = getIterator(vec);

    try
    {
        if (it != vec.end())
        {
            string numeNou;
            cout << "Introduceti numele nou: ";
            cin >> numeNou;

            (*it)->setNume(numeNou);
            cout << "Nume schimbat cu succes!" << endl;
        }
        else    throw std::runtime_error("Nu a fost gasita persoana.");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what()<<endl;
    }
}

void loadingAngajati(list<Angajat*>& v)
{
    //voi implementat tot aici condita cu nr minim de manageri operatori asistenti
    ifstream f("dataAngajati.csv");
    string buff;
    int i=0;

    while(!f.eof())
    {
        getline(f, buff);
        i++;
    }
    f.seekg (0, ios::beg);


    int auxID, type;
    string auxnume, auxprenume, auxdata;
    string auxCNP;

    int mI=0, oI=0, aI=0;

    //Populez vector
    for(int j=0; j<i; j++)
    {
        type = 3;
        if(j<10) type =2;
        if(j<5) type = 1;
        getline(f, buff);

        stringstream ss;
        ss.str(buff);

        //ID
        string aux;
        getline( ss, aux, ',' );
        auxID=stoi(aux);
        //NUME PRENUME
        getline( ss, aux, ',' );
        auxnume = aux;
        getline( ss, aux, ',' );
        auxprenume = aux;
        //CNP
        getline( ss, aux, ',' );
        auxCNP = aux;
        //data angajare
        getline( ss, aux, ',' );
        auxdata = aux;
        try
        {
            switch(type)
            {
            case 1:
                //MANAGER
                v.push_back(new Manager(auxID, auxnume, auxprenume, auxCNP, auxdata));
                mI++;
                break;
            case 2:
                //OPERATOR COMENZI
                v.push_back(new Operator(auxID, auxnume, auxprenume, auxCNP, auxdata));
                oI++;
                break;
            case 3:
                //ASISTENT
                v.push_back(new Asistent(auxID, auxnume, auxprenume, auxCNP, auxdata));
                aI++;
                break;
            default:
                throw std::runtime_error("Aici throw eerror");
                break;
            }
        }
        catch(const std::exception& e)
        {
            cerr << "Eroare:\t "<< e.what() << ". Angajat neAdaugat" <<endl;
        }
    }
    try
    {
        if(mI < 1 || oI < 3 || aI < 1)
            throw std::runtime_error("Nu este destul staff");
    }
    catch(const std::exception& e)
    {
        cerr << "Eroare:\t "<< e.what() <<endl;
        exit(1);
    }

    f.close();
}

void meniu_angajati(list<Angajat*>& vec)
{
    cout<<"\n\n----------------Meniu angajati-----------------------\n\n";
    int choice;
    cout<<"Alege operatiune: \n\t1.Agauga angajat\n\t2.Sterge Angajat\n\t3.Modificare nume angajat";
    cout<<"\n\t4.Afisare detalii angajat\n\t5.Afisare toti angajatii\n";
    cin>>choice;
    cout<<"\n\n--------------------------------------------------------\n\n";
    switch(choice)
    {
    case 1:
        createA(vec);
        break;
    case 2:
        removeA(vec);
        break;
    case 3:
        changeNume(vec);
        break;
    case 4:
        specificA(vec);
        break;
    case 5:
        cout<<"\nAfisare toti angajatii: \n\n";
        for (const auto& angajat : vec)     angajat->afisare(); // Apelăm funcția de afișare pentru fiecare angajat
        //cout<<" | "<<angajat->getSalariu()<<endl;
        break;
    default:
        break;
    }
}
