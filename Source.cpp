#include "header.h"
#include "bibliotekos.h"

int main()
{

    auto start = hrClock::now();
    int f;
    ar_failas(f);

    if (f == 1) {
        failas();
    }

    else {
        ranka();
    }

    auto end = hrClock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "\nVisos programos vykdymas uztruko: " << diff.count() << " s\n";

    return 0;
}

