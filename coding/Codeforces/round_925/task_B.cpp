// https://codeforces.com/contest/1931/problem/B
// Created by ruslan515 on 13.02.2024
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    long long avg = sum / n;
    int curr_sum = 0;
    for (int i = 0; i < n; ++i) {
        curr_sum += a[i];
        if (curr_sum < (i + 1) * avg) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";

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

