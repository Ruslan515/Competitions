// https://codeforces.com/contest/1790/problem/B
// Created by ruslan515 on 27.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n, s, r;
    cin >> n >> s >> r;
    int diff = s - r;
    int reminder = r % (n - 1);
    int middle = r / (n - 1);
    cout << diff << " ";
    for (int i = 1; i < n; ++i) {
        if (reminder > 0) {
            cout << middle + 1 << " ";
            --reminder;
        } else {
            cout << middle << " ";
        }
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