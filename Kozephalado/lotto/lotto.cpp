#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i<= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    int het;
    cin >> het;
    int huzott[52][5];
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> huzott[i][j];
        }
    }

    cout << "#" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (huzott[51][j] > huzott[51][j+1]) {
                huzott[51][j] = huzott[51][j] ^ huzott[51][j+1];
                huzott[51][j+1] = huzott[51][j] ^ huzott[51][j+1];
                huzott[51][j] = huzott[51][j] ^ huzott[51][j+1];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << huzott[51][i] << " ";
    }
    cout << endl;

    cout << "#" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (huzott[het-1][j] > huzott[het-1][j+1]) {
                huzott[het-1][j] = huzott[het-1][j] ^ huzott[het-1][j+1];
                huzott[het-1][j+1] = huzott[het-1][j] ^ huzott[het-1][j+1];
                huzott[het-1][j] = huzott[het-1][j] ^ huzott[het-1][j+1];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << huzott[het-1][i] << " ";
    }
    cout << endl;

    cout << "#" << endl;
    int szamok[91] = {0};
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 5; j++) {
            szamok[huzott[i][j]]++;
        }
    }
    bool van = false;
    for (int i = 1; i < 91; i++) {
        if (szamok[i] == 0) {
            van = true;
            break;
        }
    }
    if (van) {
        cout << "van" << endl;
    }else {
        cout << "nincs" << endl;
    }

    cout << "#" << endl;
    int paratlan = 0;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 5; j++) {
            if (huzott[i][j] % 2 == 1) {
                paratlan++;
            }
        }
    }
    cout << paratlan << endl;

    cout << "#" << endl;
    for (int i = 1; i < 91; i++) {
        cout << szamok[i] << " ";
    }
    cout << endl;

    cout << "#" << endl;
    int primek = 0;
    int primekt[91];
    for (int i = 1; i < 91; i++) {
        if (prime(i)) {
            if (szamok[i] == 0) {
                primekt[primek] = i;
                primek++;
            }
        }
    }
    cout << primek << endl;
    for (int i = 0; i < primek-1; i++) {
        for (int j = 0; j < primek - 1 - i; j++) {
            if (primekt[j] > primekt[j+1]) {
                primekt[j] = primekt[j] ^ primekt[j+1];
                primekt[j+1] = primekt[j] ^ primekt[j+1];
                primekt[j] = primekt[j] ^ primekt[j+1];
            }
        }
    }
    for (int i = 0; i < primek; i++) {
        cout << primekt[i] << " ";
    }
    cout << endl;

    return 0;
}