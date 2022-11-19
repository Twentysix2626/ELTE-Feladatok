#include <bits/stdc++.h>

using namespace std;

struct szamokStruct {
    int kezdo, kezdp, kezdm, vego, vegp, vegm;
    int szam;
    char tipus;
};


int main(int argc, char **argv) {
    int n, temp;
    cin >> n;
    struct szamokStruct szamok[n];
    int pm, pv;
    cin >> pv >> pm;
    // Beolvasunk O(n)
    for (int i = 0; i < n; i++) {
        cin >> szamok[i].kezdo >> szamok[i].kezdp >> szamok[i].kezdm >> szamok[i].vego >> szamok[i].vegp >> szamok[i].vegm >> szamok[i].szam;
    }

    cout << "#" << endl;
    // Eldontjuk a tipusat a szamnak O(n)
    for (int i = 0; i < n; i++) {
        temp = szamok[i].szam / 1000000;
        if (temp == 20 || temp == 30 || temp == 70) {
            cout << "m";
            szamok[i].tipus = 'm';
        }else {
            cout << "v";
            szamok[i].tipus = 'v';
        }
    }
    cout << endl;

    cout << "#" << endl;
    int vm = 0, mm = 0, csm = 0, csv = 0;
    // Kiszamoljuk a perceket O(n)
    for (int i = 0; i < n; i++) {
        int kezdosec, vegsec;
        kezdosec = szamok[i].kezdo * 3600 + szamok[i].kezdp * 60 + szamok[i].kezdm;
        vegsec = szamok[i].vego * 3600 + szamok[i].vegp * 60 + szamok[i].vegm;
        int dursec = vegsec - kezdosec;
        if (szamok[i].tipus == 'm') {
            mm += dursec;
            if (szamok[i].kezdo >= 7 && szamok[i].kezdo <= 17) {
                csm += dursec;
            }
        }else {
            vm += dursec;
            if (szamok[i].kezdo >= 7 && szamok[i].kezdo <= 17) {
                csv += dursec;
            }
        }
        cout << ceil((float)dursec / 60) << " " << szamok[i].szam << " ";
    }
    cout << endl;

    cout << "#" << endl;
    int csucsido = 0;
    // Megszamoljuk a csucsidoket O(n)
    for (int i = 0; i < n; i++) {
        if (szamok[i]. kezdo >= 7 && szamok[i]. kezdo <= 17) {
            csucsido++;
        }
    }
    cout << csucsido << " " << n - csucsido << endl;

    cout << "#" << endl;
    cout << ceil((float) mm / 60) << " " << ceil((float) vm / 60) << endl;

    cout << "#" << endl;
    int csucsdij = pm * ceil((float) csm / 60) + pv * ceil((float) csv / 60);
    cout << csucsdij << endl;

    return 0;
}

// kovacs. <3l