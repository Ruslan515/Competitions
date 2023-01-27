// https://codeforces.com/contest/1790/problem/A
// Created by ruslan515 on 27.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n - 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> v[i][j];
        }
    }

    int x = -1, y = -1;

    for (int i = 0; i < n; ++i) {
        int f = 0;
        for (int k = 0; k < n; ++k) {
            if (i == k) {
                continue;
            }
            if (v[i][1] == v[k][0]) {
                x = i;
                y = k;
                f = 1;
                break;
            }
        }
        if (f == 1) {
            break;
        }
    }

    cout << v[x][0] << " ";
    for (int i = 0; i < n - 1; ++i) {
        cout << v[y][i] << " ";
    }
    cout << "\n";

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