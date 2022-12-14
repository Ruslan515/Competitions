// https://codeforces.com/contest/1766/problem/B
// Created by ruslan515 on 14.12.22.
//

#include <iostream>

using namespace std;

string notepad(string s, int n) {
    string ans = "NO";
    for (int i = 2; i < n; ++i) {
        int j = 0;
        char temp = s[i];
        while (j < i && s[j] != temp) {
            ++j;
        }
        if (j != i) {
            int count = 1;
            ++j;
            char t1 = s[j];
            char t2 = s[i + count];
            while (j < i && t1 == t2) {
                ++j;
                ++count;
                t1 = s[j];
                t2 = s[i + j];
            }
            if (count > 1) {
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