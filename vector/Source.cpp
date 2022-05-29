#include "header.h"
#include "bibliotekos.h"

int main()
{
    int testi = 1; int f; int pat = 0;

    while (testi == 1) {

        ar_failas(f);

        if (f == 1) {
            failas();
        }

        else {
            ranka();
        }
        cout << ("Ar norite dirbti su kitu failu? 1 - Taip, 0 - Ne "); cin >> testi;
        do {
            if (testi == 0 || testi == 1) pat = 1;
            else {
                cout << "Ar norite dirbti su kitu failu? 1 - Taip, 0 - Ne "; cin >> testi;
            }
        } while (pat == 0);
    }

    system("pause");

    return 0;
}
