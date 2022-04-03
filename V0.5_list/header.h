
#ifndef HEADER_H
#define HEADER_H
#include "bibliotekos.h"

struct Studentas
{
    string vardas = "";
    string pavarde = "";
    list <double>nd;
    int egz = 0;
    int sum = 0;
    double rez = 0;
    double med = 0;
    int grupe = 0; // Jeigu grupe 1 - protingas 0 - vargsiukas
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
void file_isvedimas(list<Studentas> protingi, list<Studentas> vargsiukai, int sk, double& isvedimas1, double& isvedimas2);
void vertinimas(list<Studentas> list, list <Studentas> protingi, list<Studentas>& vargsiukai, double& pazangumas);
void sort_mok(list<Studentas>& list);
void laikas(double sukurimas, double ivedimas, double rusiavimas, double isvedimas1, double isvedimas2, int sk);
void generavimas_skaiciai(string& pav);
#endif