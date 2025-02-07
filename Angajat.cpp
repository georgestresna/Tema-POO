#include "Angajat.h"

bool is18(string& cnp) {
    if (cnp.length() != 13)     return false;

    int year = stoi(cnp.substr(1, 2));
    int month = stoi(cnp.substr(3, 2));
    int day = stoi(cnp.substr(5, 2));

    int gender = cnp[0] - '0';
    if (gender == 1 || gender == 2)         year += 1900;
    else if (gender == 5 || gender == 6)    year += 2000;


    time_t t = time(0);
    struct tm currentTime;
    localtime_s(&currentTime, &t);

    int cYear = currentTime.tm_year + 1900;
    int cMonth = currentTime.tm_mon + 1;
    int cDay = currentTime.tm_mday;

    int age = cYear - year;
    if (cMonth < month || (cMonth == month && cDay < day)) {
        age--;
    }

    return age >= 18;
}

Angajat::Angajat(int a, string b, string c, string d, string e)
    :ID(a), nume(b), prenume(c), CNP(d), data_angajare(e)
{
    //Verif CNP
    //string aux;
    //luna: nu mai mare de 12
    //zi: trebuie implementat pentru luni diferite conditie if diferita
    //strncpy(aux, &CNP[3], 2); aux[3]='\0';
    if(stoi(CNP.substr(3, 2)) > 12) throw std::runtime_error("Eroare la luna");
    //strncpy(aux, &CNP[5], 2); aux[3]='\0';
    if(stoi(CNP.substr(5, 2)) > 31) throw std::runtime_error("Eroare la zi");

    if(nume.length() < 3 || nume.length() > 30) throw std::runtime_error("Eroare la nume");
    if(prenume.length() < 3 || prenume.length() > 30) throw std::runtime_error("Eroare la prenume");
    if(!is18(CNP))   throw std::runtime_error("Nu are 18 ani!");
}

void Angajat::afisare()const
{
    cout<<"Date angajat: "<<ID<<" "<<nume<<" "<<prenume<<" "<<CNP<<" "<<data_angajare<<" Salariu: ";
}

double Angajat::getSalariu() const
{
    double salariu =3500;

    struct tm angajare= {0};
    istringstream ss(data_angajare);
    time_t current = time(NULL);

    ss >> get_time(&angajare, "%Y-%m-%d");
    double seconds = difftime(current, mktime(&angajare));
    seconds = seconds / 31556926;   //seconds to years
    salariu += 100*(int)seconds;
    salariu += comision * 0.005;
    return salariu;
}

void Angajat::setNume(const string new_nume)
{
    nume = new_nume;
}

int Angajat::getID()
{
    return ID;
}

int Angajat::getComision(){
    return comision;
}

string Angajat::getNume() const{
    return nume;
}
