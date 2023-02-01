// https://codeforces.com/contest/1790/problem/A
// Created by ruslan515 on 27.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    int i;
    int prev, curr;
    cin >> prev;
    int sum = prev;
    int idx = -1;
    int idx_neg = -1;
    if (prev == -1) {
        idx_neg = 0;
    }
    for (i = 1; i < n; ++i) {
        cin >> curr;
        sum += curr;
        if (prev == curr && curr == -1) {
            idx = i - 1;
        } else if (curr == -1) {
            idx_neg = i;
        }
        prev = curr;
    }

    if (idx != -1) {
        sum += 4;
    } else if (idx_neg == -1) {
        sum -= 4;
    }

    cout << sum << "\n";

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