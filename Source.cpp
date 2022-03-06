#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::mt19937;
using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_distribution;


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
void tikr_random(string& ar_random);
void ivestis(Studentas& temp);
void isvestis(Studentas& temp);
void vidurkis(Studentas& temp);
void mediana(Studentas& temp);
bool compare_name(const Studentas &a, const Studentas &b);
bool compare_last(const Studentas& a, const Studentas& b);
void file_isvedimas(vector<Studentas> list, int sk);

int main()
{
    int f;
    ar_failas(f);

    if (f == 1) {
        failas();
    }

    else {

        int s;
        int nd_sk = 0, index = 0;

        do {
            cout << "Kiek yra studentu: "; cin >> s;

            if (s) index = 1;

            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Neteisingas ivedimas" << endl;
            }

        } while (index == 0);

        Studentas* arr = new Studentas[s];
        for (int i = 0; i < s; i++)
        {
            ivestis(arr[i]);
        }
        for (int i = 0; i < s; i++)
        {
            vidurkis(arr[i]);
            mediana(arr[i]);
        }

        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
            << "Galutinis vid. " << "/ Galutinis med." << endl;

        for (int i = 0; i < s; i++)
        {
            isvestis(arr[i]);
        }
        delete[] arr;
        system("pause");
        return 0;
    }
}

void ar_failas(int& f) {

    string f1; int f_i = 0;

    do {
        cout << "Kaip bus gaunami duomenys? 1 - is failo, 0 - ivedami ranka "; cin >> f1;
        if (f1 == "1" || f1 == "0")f_i = 1;
        else cout << "Klaidingas ivedimas" << endl;
    } while (f_i == 0);

    if (f1 == "1") f = 1;
    else f = 0;
}

void failas() {
    vector <Studentas> list;
    Studentas nw;
    string eilute;

    std::ifstream fd("kursiokai.txt");

    if (fd.is_open()) {
        int nd, egz;
        int stulpeliu_sk = 0, mokiniu_sk = 0;
        std::getline(fd, eilute);
        std::stringstream x;
        x << eilute;
        string zodis;
        while (x >> zodis) stulpeliu_sk++;

        for (int line = 0; std::getline(fd, eilute); line++) {
            mokiniu_sk++;
        }

        fd.clear();
        fd.seekg(0);
        std::getline(fd, eilute);


        for (int i = 0; i < mokiniu_sk; i++) {
            nw.sum = 0;
            fd >> nw.vardas >> nw.pavarde;
            for (int j = 0; j < stulpeliu_sk - 3; j++) {
                fd >> nd;
                nw.nd.push_back(nd);
                nw.sum = nw.sum + nd;
            }

            fd >> nw.egz;
            vidurkis(nw);
            mediana(nw);
            nw.nd.clear();
            list.push_back(nw);

        }
        fd.close();

        string rusiavimas; int r_i = 0;

        do {
            cout << "Pagal ka norite isrusiuoti faila? 1 - Vardus 0 - Pavardes "; cin >> rusiavimas;
            if (rusiavimas == "1" || rusiavimas == "0")r_i = 1;
            else cout << "Klaidingas ivedimas" << endl;
        } while (r_i == 0);

        if (rusiavimas == "1") std::sort(list.begin(), list.end(), compare_name);
        else std::sort(list.begin(), list.end(), compare_last);

        file_isvedimas(list, mokiniu_sk);
    }

    else {
        cout << "Nepavyko atidaryti duomenu failo" << endl;
    }
}


void tikr_random(string& ar_random) {
    do {
        cout << "Ar norite, kad programa generuotu atsitiktinius pazymius? 1-taip, 0-ne: "; cin >> ar_random;
        if (ar_random != "1" && ar_random != "0") {
            cout << "Klaidingas ivedimas" << endl;
        }
    } while (ar_random != "1" && ar_random != "0");

}

void ivestis(Studentas& temp)
{
    int nd, egz;
    int i = 0;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    string stop, ar_random;
    tikr_random(ar_random);

    if (ar_random == "0") {
        do
        {
            cout << "Iveskite " << i + 1 << "-a(-i) pazymi:"; cin >> nd;
            if (nd) {
                if (nd > 0 && nd <= 10)
                {

                    temp.nd.push_back(nd);
                    temp.sum += nd;

                    i++;
                    cout << "Ar dar yra pazymiu? 1-taip, 0-ne: "; cin >> stop;

                    if (stop != "0" && stop != "1") {
                        do {
                            cout << "Neteisingas ivedimas" << endl;
                            cout << "Ar dar yra pazymiu? 1-taip, 0-ne: "; cin >> stop;
                        } while (stop != "0" && stop != "1");
                    }
                }

                else {
                    cout << "Neteisingas ivedimas" << endl;
                }
            }

            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Neteisingas ivedimas" << endl;
            }

        } while (stop != "0");

        int index = 0;
        do {
            cout << "Iveskite egzamino iverti:"; cin >> egz;
            if (egz) {
                if (egz > 0 && egz <= 10)
                {
                    temp.egz = egz;
                    index = 1;

                }

                else {
                    cout << "Neteisingas ivedimas" << endl;
                }
            }

            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Neteisingas ivedimas" << endl;
            }


        } while (index == 0);
    }

    else {

        int kiek;
        int index = 0;

        mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
        int_distribution dist(1, 10);

        do {
            cout << "Kiek bus pazymiu gavo studentas(ne daugiau 20)? "; cin >> kiek;

            if (kiek) {
                if (kiek < 0 || kiek > 20) {
                    cout << "Neteisingas ivedimas" << endl;
                }
                else {
                    index = 1;
                }
            }
            else {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Neteisingas ivedimas" << endl;
            }

        } while (index == 0);


        for (int i = 0; i < kiek; i++)
        {
            nd = dist(mt);
            cout << "Sugeneruotas " << i + 1 << "-as pazymys: " << nd << endl;
            temp.nd.push_back(nd);
            temp.sum = temp.sum + nd;
        }

        temp.egz = dist(mt);
        cout << "Atsitiktinai sugeneruotas egzamino pazymus: " << temp.egz << endl;
        

    }
}

void isvestis(Studentas& temp)
{

    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.rez
        << temp.med << endl;
}

void vidurkis(Studentas& temp)
{
    size_t nd_sk = temp.nd.size();
    double nd_vid = (double)temp.sum / nd_sk;
    temp.rez = 0.4 * nd_vid + 0.6 * temp.egz;

}

void mediana(Studentas& temp)
{
    double med;
    sort(temp.nd.begin(), temp.nd.end());
    if (temp.nd.size() % 2 == 0)
    {
        med = (temp.nd[temp.nd.size() / 2 - 1] + temp.nd[temp.nd.size() / 2]) / 2;
    }
    else
    {
        med = temp.nd[temp.nd.size() / 2];
    }

    temp.med = 0.4 * med + 0.6 * temp.egz;
}

bool compare_name(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}

bool compare_last(const Studentas& a, const Studentas& b) {
    return a.pavarde < b.pavarde;
}

void file_isvedimas(vector<Studentas> list, int sk) {
    
    string file; int f_i = 0;

    do {
        cout << "Kokios isvedimo norite? 1 - I faila, 0 - Paprasto "; cin >> file;
        if (file == "1" || file == "0") f_i = 1;
        else cout << "Klaidingas ivedimas" << endl;
    } while (f_i == 0);

    if (file == "0") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
            << "Galutinis vid. " << "/ Galutinis med." << endl;

        for (int i = 0; i < sk; i++) {
            cout << setw(20) << list[i].vardas << setw(20) << list[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << list[i].rez
                << list[i].med << endl;
        }
    }

    else {
        std::ofstream fr("rez1.txt");

        fr << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
            << "Galutinis vid. " << "/ Galutinis med." << endl;

        for (int i = 0; i < sk; i++) {
            fr << setw(20) << list[i].vardas << setw(20) << list[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << list[i].rez
                << list[i].med << endl;
        }
        fr.close();
    }
}