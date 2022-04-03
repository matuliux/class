#include "header.h"
#include "bibliotekos.h"


void failas() {
    deque <Studentas> list, protingi, vargsiukai;
    Studentas nw;
    string eilute, tip; int t_i = 0;
    double sukurimas = 0, ivedimas = 0, pazangumas = 0, isvedimas1 = 0, isvedimas2 = 0;
    cout << "Koki faila naudosite? 1 - Paruosta 0 - Generuoti nauja "; cin >> tip;
    do {
        if (tip == "0" || tip == "1") t_i = 1;
        else {
            cout << "Klaidingas ivedimas \nKoki faila naudosite? 1 - Paruosta 0 - Generuoti nauja "; cin >> tip;
        }
    } while (t_i == 0);

    string pav;

    if (tip == "1") {
        cout << "Iveskite koki faila noresite atidaryti: "; cin >> pav;
    }
    else {
        auto start = hrClock::now();
        generavimas_skaiciai(pav);
        auto end = hrClock::now();
        std::chrono::duration<double> diff = end - start;
        sukurimas = diff.count();
    }

    std::ifstream fd(pav);
    try {
        if (fd.is_open()) {
            int nd, egz;
            int stulpeliu_sk = 0, mokiniu_sk = 0;
            std::getline(fd, eilute);
            std::stringstream x;

            auto start = hrClock::now();
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
            auto end = hrClock::now();
            std::chrono::duration<double> diff = end - start;
            ivedimas = diff.count();

            sort_mok(list);
            vertinimas(list, protingi, vargsiukai, pazangumas);
            file_isvedimas(protingi, vargsiukai, mokiniu_sk, isvedimas1, isvedimas2);
            laikas(sukurimas, ivedimas, pazangumas, isvedimas1, isvedimas2, mokiniu_sk);
        }
        else {
            throw "Nepavyko atidaryti duomenu failo";
        }
    }
    catch (const char* e) {
        cout << e << "\n";
    }
}


void ar_failas(int& f) {

    string f1; int f_i = 0;

    do {
        cout << "Kaip bus gaunami duomenys? 1 - is failo, 0 - ivedami ranka "; cin >> f1;
        if (f1 == "1" || f1 == "0")f_i = 1;
        else cout << "Klaidingas ivedimas" << "\n";
    } while (f_i == 0);

    if (f1 == "1") f = 1;
    else f = 0;
}

void isvestis(Studentas& temp)
{

    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.rez
        << temp.med << "/n";
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


void file_isvedimas(deque<Studentas> protingi, deque<Studentas> vargsiukai, int sk, double& isvedimas1, double& isvedimas2) {

    string file; int f_i = 0;

    do {
        cout << "Kokios isvedimo norite? 1 - I faila, 0 - Paprasto "; cin >> file;
        if (file == "1" || file == "0") f_i = 1;
        else cout << "Klaidingas ivedimas" << "\n";
    } while (f_i == 0);

    if (file == "0") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
            << "Galutinis vid. " << "/ Galutinis med." << "\n";

        /*for (int i = 0; i < sk; i++) {
            cout << setw(20) << list[i].vardas << setw(20) << list[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << list[i].rez
                << list[i].med << "\n";
        }*/
    }

    else {
        std::ofstream fr("protingi.txt");
        std::ofstream fu("vargsiukai.txt");

        fr << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
            << "Galutinis vid. " << "/ Galutinis med." << "\n";

        fu << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
            << "Galutinis vid. " << "/ Galutinis med." << "\n";

        auto start = hrClock::now();
        for (deque<Studentas>::size_type i = 0; i != protingi.size(); i++) {
            fr << setw(20) << protingi[i].vardas << setw(20) << protingi[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << protingi[i].rez
                << protingi[i].med << "\n";
        }

        auto end = hrClock::now();
        std::chrono::duration<double> diff = end - start;
        isvedimas1 = diff.count();

        auto start1 = hrClock::now();
        for (deque<Studentas>::size_type i = 0; i != vargsiukai.size(); i++) {
            fu << setw(20) << vargsiukai[i].vardas << setw(20) << vargsiukai[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << vargsiukai[i].rez
                << vargsiukai[i].med << "\n";
        }
        auto end1 = hrClock::now();
        std::chrono::duration<double> diff1 = end - start;
        isvedimas2 = diff1.count();

        fr.close();
        fu.close();
    }

}

void vertinimas(deque<Studentas> list, deque<Studentas>& protingi, deque<Studentas>& vargsiukai, double& pazangumas) {
    auto start = hrClock::now();
    for (auto& kint : list) { //(auto &kint:list)
        if (kint.rez < 5) vargsiukai.push_back(kint);
        else {
            protingi.push_back(kint);
        }
    }
    auto end = hrClock::now();
    std::chrono::duration<double> diff = end - start;
    pazangumas = diff.count();
    list.clear();

}

void sort_mok(deque<Studentas>& list) {

    std::sort(list.begin(), list.end(), compare_last);

}

void laikas(double sukurimas, double ivedimas, double rusiavimas, double isvedimas1, double isvedimas2, int sk) {
    printf("\n%d Studentu failo sukurimas uztruko: %f s\n", sk, sukurimas);
    printf("%d Studentu nuskaitymas is failo uztruko: %f s\n", sk, ivedimas);
    printf("%d Studentu isrusiavimas i vargsus ir protingus uztruko: %f s\n", sk, rusiavimas);
    printf("Protingu isvedimas i faila: %f s\n", isvedimas1);
    printf("Vargsiuku isvedimas i faila: %f s\n", isvedimas2);
    printf("\nVisos programos vykdymas uztruko: %f", sukurimas + ivedimas + rusiavimas + isvedimas1 + isvedimas2);
}
