#include "header.h"
#include "bibliotekos.h"

void ranka() {
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