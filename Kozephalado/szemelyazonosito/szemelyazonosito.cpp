#include <bits/stdc++.h>

using namespace std;


int main(int argc, char **argv) {
    unsigned long long int azonosito1, azonosito2;
    int evszam;
    cin >> azonosito1 >> azonosito2 >> evszam;
    int elso1 = azonosito1 / 1000000000;
    int elso2 = azonosito2 / 1000000000;

    cout << "#" << endl;
    if (elso1 == 1 || elso1 == 3) {
        cout << "ferfi" << endl;
    }else {
        cout << "no" << endl;
    }

    cout << "#" << endl;
    cout << azonosito1 % 100 << endl;

    cout << "#" << endl;
    int elsoev;
    if (elso1 == 1 || elso1 == 2) {
        elsoev = evszam - (1900 + (azonosito1 / 10000000) % 100);
        cout << elsoev << endl;
    }else {
        elsoev = evszam - (2000 + (azonosito1 / 10000000) % 100);
        cout << elsoev << endl;
    }

    cout << "#" << endl;
    int masodikev;
    if (elso2 == 1 || elso2 == 2) {
        masodikev = evszam - (1900 + (azonosito2 / 10000000) % 100);
    }else {
        masodikev = evszam - (2000 + (azonosito2 / 10000000) % 100);
    }
    int kulonbseg = sqrt(pow(elsoev-masodikev, 2));
    cout << kulonbseg << endl;

    cout << "#" << endl;
    if (elsoev > masodikev) {
        cout << azonosito1 << endl;
    }else if (elsoev < masodikev) {
        cout << azonosito2 << endl;
    }else {
        if (azonosito1 % 100 < azonosito2 % 100) {
            cout << azonosito1 << endl;
        }else {
            cout << azonosito2 << endl;
        }
    }

    cout << "#" << endl;
    unsigned long long int teljesaz2 = azonosito2 * 10;
    int ellenorzo = 0;
    for (int i = 1; i <= 10; i++) {
        ellenorzo = ellenorzo + (((unsigned long long int)(azonosito2 / pow(10, i-1)) % 10)) * i;
    }
    ellenorzo = ellenorzo % 11;
    teljesaz2 += ellenorzo;
    if (ellenorzo == 10) {
        cout << "hiba" << endl;
    }else {
        cout << teljesaz2 << endl;
    }

    return 0;
}

// kovacs. <l3