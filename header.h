#ifndef HEADER_H
#define HEADER_H
#include "bibliotekos.h"

struct Studentas
{
    string vardas = "";
    string pavarde = "";
    vector <double>nd;
    int egz = 0;
    int sum = 0;
    double rez = 0;
    double med = 0;
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
void file_isvedimas(vector<Studentas> list, int sk);

#endif