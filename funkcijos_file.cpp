#include "header.h"
#include "bibliotekos.h"


void failas() {
    vector <Studentas> list;
    Studentas nw;
    string eilute;

    std::ifstream fd("kursiokai.txt");
    try {
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
            throw "Nepavyko atidaryti duomenu failo";
        }
    }
    catch(const char *e){
        cout << e << endl;
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

//-------------------------------------------------------
//Bendros funkcijos
//-------------------------------------------------------


bool compare_name(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}

bool compare_last(const Studentas& a, const Studentas& b) {
    return a.pavarde < b.pavarde;
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