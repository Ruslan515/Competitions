// https://contest.yandex.ru/contest/53027/problems/D/
// Created by ruslan515 on 03.11.23.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 =s1.size(), n2 = s2.size();
    if (n1 != n2) {
        cout << "NO\n";
    }
    map<char, int> mp1, mp2;
    for (int i = 0; i < n1; ++i) {
        mp1[s1[i]]++;
        mp2[s2[i]]++;
    }
    map<char, int> ::iterator it = mp1.begin();
    char key;
    int val;
    for (; it != mp1.end(); ++it) {
        key = it->first;
        val = it->second;
        if (mp2.find(key) == mp2.end() || mp2[key] != val) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}