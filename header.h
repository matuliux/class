#ifndef HEADER_H
#define HEADER_H
#include "bibliotekos.h"

class Studentas
{
private:
    string c_vardas;
    string c_pavarde;
    vector <double>c_nd;
    int c_egz;
    int c_sum;
    double c_rez;
    double c_med;

public:
    //Konstruktorius
    Studentas() {
        c_vardas = "";
        c_pavarde = "";
        c_egz = 0;
        c_sum = 0;
        c_rez = 0;
        c_med = 0;
    }

    //Destruktorius
    ~Studentas() { c_nd.clear(); }

    //Kopijavimo konstruktorius (f(g))
    Studentas(const Studentas& temp){
        c_vardas = temp.c_vardas;
        c_pavarde = temp.c_pavarde;
        c_egz = temp.c_egz;
        c_sum = temp.c_sum;
        c_rez = temp.c_rez;
        c_med = temp.c_med;
        c_nd = temp.c_nd;
    }

    //Priskirimo konstruktorius (f = g)
    Studentas& operator=(const Studentas& temp) {
        if (this == &temp) {
            return *this;
        }
        c_vardas = temp.c_vardas;
        c_pavarde = temp.c_pavarde;
        c_egz = temp.c_egz;
        c_sum = temp.c_sum;
        c_rez = temp.c_rez;
        c_med = temp.c_med;
        c_nd = temp.c_nd;
        return *this;
    }


    inline string getVardas() const { return c_vardas; }
    void setVardas(string vardas) { c_vardas = vardas; }
    inline string getPavarde() const { return c_pavarde; }  // get'eriai, inline
    void setPavarde(string pavarde) { c_pavarde = pavarde; }

    double getNd(int i) const { return c_nd.at(i); }
    void setNd(double nd) { c_nd.push_back(nd); }
    void clearNd() { c_nd.clear(); }
    inline int getNdSize() { return c_nd.size(); }
    void sortNd() { sort(c_nd.begin(), c_nd.end()); }

    inline int getEgz() const { return c_egz; }
    void setEgz(int egz) { c_egz = egz; }

    inline double getRez() const { return c_rez; }
    void setRez(double rez) { c_rez = rez; }

    inline double getMed() const { return c_med; }
    void setMed(double med) { c_med = med; }

    inline int getSum() const { return c_sum; }
    void addSum(int sum) { c_sum += sum; }
    void setSumNull() { c_sum = 0; }

};

void ar_failas(int& f);
void failas();
void ranka();
void tikr_random(string& ar_random);
void ivestis(Studentas& temp);
void isvestis(Studentas& temp);
void vidurkis(Studentas& temp);
void mediana(Studentas& temp);
bool compare_name(const Studentas& a, const Studentas& b);
bool compare_last(const Studentas& a, const Studentas& b);
void file_isvedimas(vector<Studentas> protingi, vector<Studentas> vargsiukai, int sk, double& isvedimas1, double& isvedimas2);
void vertinimas(vector<Studentas>& protingi, vector<Studentas>& vargsiukai, double& pazangumas);
void sort_mok(vector<Studentas>& list);
void laikas(double sukurimas, double ivedimas, double rusiavimas, double isvedimas1, double isvedimas2, int sk);
void generavimas_skaiciai(string& pav);
bool Maziau(const Studentas& a);
#endif