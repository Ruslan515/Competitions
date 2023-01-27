// https://codeforces.com/contest/1790/problem/A
// Created by ruslan515 on 27.01.23.
//

#include <bits/stdc++.h>

using namespace std;

const string PI = "314159265358979323846264338327";

void solving() {
    string n;
    cin >> n;
    int i;
    for (i = 0; i < n.size(); ++i) {
        char ch_n = n[i];
        char ch_PI = PI[i];
        if (ch_PI != ch_n) {
            break;
        }
    }

    cout << i << "\n";

    return;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}