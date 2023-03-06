// https://codeforces.com/contest/1794/problem/0
// Created by ruslan515 on 04.03.23.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    if (n == 2) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 != s2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        return;
    }

    vector<string> vStr(2 * n - 2);
    map<int, vector<int>> vLen;
    string s;
    for (int i = 0; i < 2 * n - 2; ++i) {
        cin >> s;
        vStr[i] = s;
        vLen[s.size()].push_back(i);
    }

    string s1, s2;
    int idx1, idx2;
    int len = n - 1;
    idx1 = vLen[len][0];
    idx2 = vLen[len][1];
    s1 = vStr[idx1];
    s2 = vStr[idx2];
    string sub1 = s1.substr(1);
    string sub2 = s2.substr(0, n - 2);
    if (sub1 != sub2) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    sub2 = s2[n - 2];
    string f = s1 + sub2;
//    cout << f << "\n";

    int sizeS = f.size();
    for (int i = 0; i < sizeS / 2; ++i) {
        if (f[i] != f[n - i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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

