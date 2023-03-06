// https://codeforces.com/contest/1794/problem/B
// Created by ruslan515 on 04.03.23.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ++a[i];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int d = a[i + 1] % a[i];
        if (d == 0) {
            a[i + 1]++;
        }
        cout << a[i] << " ";
    }
    cout << a[n - 1] << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

//    cout << 2 << " " << 5 << " " << 4 << " " << 6 << "\n";
//    cout << 3 << " " << 2 << " " << 3 << "\n";
//    cout << 4 << " " << 2 << "\n";

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}

