#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::left;
using std::right;
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

void tikr_random(string& ar_random);
void ivestis(Studentas& temp);
void isvestis(Studentas& temp);
void vidurkis(Studentas& temp);
void mediana(Studentas& temp);
int main()
{
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

    for (int i = 0; i < s; i++)
    {
        isvestis(arr[i]);
    }
    delete[] arr;
    system("pause");
    return 0;
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
        srand((unsigned int)time(NULL));

        int kiek;
        int index = 0;

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
            nd = (rand() % 10) + 1;
            cout << "Sugeneruotas " << i + 1 << "-as pazymys: " << nd << endl;
            temp.nd.push_back(nd);
            temp.sum = temp.sum + nd;
        }

        temp.egz = (rand() % 10) + 1;
        cout << "Atsitiktinai sugeneruotas egzamino pazymus: " << temp.egz << endl;

    }
}

void isvestis(Studentas& temp)
{
    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde"
        << "Galutinis vid. " << "/ Galutinis med." << endl;
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