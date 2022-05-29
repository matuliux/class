#ifndef HEADER_H
#define HEADER_H
#include "bibliotekos.h"
#include "Vector.h"

class Zmogus {
protected:
    string c_vardas;
    string c_pavarde;
public:
    inline string getVardas() const { return c_vardas; }
    virtual void setVardas(string vardas) = 0;
    inline string getPavarde() const { return c_pavarde; }
    virtual void setPavarde(string pavarde) = 0;
};


class Studentas : public Zmogus
{
private:
    Vector <double>c_nd;
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
    Studentas(const Studentas& temp) {
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



    void setVardas(string vardas) { c_vardas = vardas; }
    void setPavarde(string pavarde) { c_pavarde = pavarde; }

    double getNd(int i) const { return c_nd.at(i); }
    void setNd(double nd) { c_nd.push_back(nd); }
    void clearNd() { c_nd.clear(); }
    inline int getNdSize() { return c_nd.size(); }
    void sortNd() { std::sort(c_nd.begin(), c_nd.end()); }

    inline int getEgz() const { return c_egz; }
    void setEgz(int egz) { c_egz = egz; }

    inline double getRez() const { return c_rez; }
    void setRez(double rez) { c_rez = rez; }

    inline double getMed() const { return c_med; }
    void setMed(double med) { c_med = med; }

    inline int getSum() const { return c_sum; }
    void addSum(int sum) { c_sum += sum; }
    void setSumNull() { c_sum = 0; }

    inline double getNauj() const { return (c_med + c_rez) / 2.0; }

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
void file_isvedimas(Vector<Studentas> protingi, Vector<Studentas> vargsiukai, int sk, double& isvedimas1, double& isvedimas2);
bool pazymiai_sort(const Studentas& a, const Studentas& b);
void vertinimas(Vector<Studentas>& protingi, Vector<Studentas>& vargsiukai, double& pazangumas);
void sort_mok(Vector<Studentas>& list);
void laikas(double sukurimas, double ivedimas, double rusiavimas, double isvedimas1, double isvedimas2, int sk);
void generavimas_skaiciai(string& pav);
bool Maziau(const Studentas& a);
#endif