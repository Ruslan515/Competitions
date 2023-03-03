// https://codeforces.com/contest/1800/problem/A
// Created by ruslan515 on 02.03.23.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = 0;
    map<int, set<char>> mp;
    mp[0] = {'m', 'M'};
    mp[1] = {'e', 'E'};
    mp[2] = {'o', 'O'};
    mp[3] = {'w', 'W'};
    int i = 0;
    char temp;
    for (idx = 0; idx < 4 && i < n; ++idx) {
        set<char> st = mp[idx];
        temp = s[i];
        if (st.count(temp) == 0) {
            break;
        }
        while (i < n && st.count(temp)) {
            ++i;
            temp = s[i];
        }

    }
    string ans = "YES";
    if (idx != 4 || i != n) {
        ans = "NO";
    }
    cout << ans << "\n";

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

