#include <bits/stdc++.h>

using namespace std;

string transf(string input) {
    int hosszIn = size(input);
    // Kivesszuk a nem a-z & A-Z elemeket WC: O(n)(?)
    for (int i = 0; i < hosszIn; i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))) {
            for (int j = i; j < hosszIn; j++) {
                input[j] = input[j + 1];
            }
            hosszIn--;
            i--;
        }
    }

    // String szemet torles O(1)
    input.erase(hosszIn, size(input));
    // Nagybetukke alakitas O(n)
    for (int i = 0; i < hosszIn; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] -= 32;
        }
    }

    return input;
}


int main(int argc, char **argv) {
    string input;
    string key;

    getline(cin, input);
    input = transf(input);
    getline(cin, key);
    key = transf(key);
    
    cout << "#" << endl;
    cout << input << endl;
    cout << "#" << endl;
    cout << key << endl;

    cout << "#" << endl;
    int n = size(input);
    int output[n];
    // Atvaltjuk a szamokat O(n)+180/26 (?)
    for (int i = 0; i < n; i++) {
        output[i] = (input[i] - 65) + (key[i%size(key)] - 65);
        while (output[i] >= 26) {
            output[i]-=26;
        }
        output[i]+=65;
    }
    // O(n)
    for (int i = 0; i < n; i++) {
        cout << (char) output[i];
    }
    cout << endl;

    
    return 0;
}

// kovacs. <l3