// https://codeforces.com/contest/1796/problem/B
// Created by ruslan515 on 28.02.23.
//

#include <bits/stdc++.h>

using namespace std;

string solving() {
    string ans = "NO\n";
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    if (a[0] == b[0]) {
        ans = "YES\n";
        ans += a[0];
        ans += "*\n";

    } else if (a[n - 1] == b[m - 1]) {
        ans = "YES\n";
        ans += "*";
        ans += a[n - 1];
        ans += "\n";

    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i] == b[j] && (i < n - 1 && j < m - 1) && (a[i + 1] == b[j + 1])) {
                    ans = "YES\n";
                    ans += "*";
                    ans += a[i];
                    ans += a[i + 1];
                    ans += "*\n";
                    break;
                }
            }
        }
    }


    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solving();
    }

    return 0;
}