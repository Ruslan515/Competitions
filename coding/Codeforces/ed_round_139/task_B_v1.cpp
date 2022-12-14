// https://codeforces.com/contest/1766/problem/B
// Created by ruslan515 on 14.12.22.
//

#include <iostream>
#include <map>

using namespace std;

string notepad(string s, int n) {
    string ans = "NO";
    map<string, int> mp;
    string temp = "";
    for (int i = 0; i < n - 1; ++i) {
        temp = s.substr(i, 2);
        if (mp.find(temp) == mp.end()) {
            mp[temp] = i;
        } else {
            if (mp[temp] < i - 1) {
                ans = "YES";
                break;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> s;
        string ans = notepad(s, n);
        cout << ans << "\n";
    }

    return 0;
}