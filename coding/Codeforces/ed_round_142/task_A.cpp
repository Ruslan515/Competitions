// https://codeforces.com/contest/1792/problem/A
// Created by ruslan515 on 24.01.23.
//

#include <bits/stdc++.h>

using namespace std;

long long solving() {
    long long n;
    cin >> n;
    vector<long long > vec;
    long long cnt = 0;
    long long temp;
    for (long long i = 0; i < n; ++i) {
        cin >> temp;
        vec.push_back(temp);
        if (vec[i] == 1)
            ++cnt;
    }

    long long ans = n - cnt + cnt / 2;
    if (cnt % 2 != 0)
        ++ans;
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        cout << solving() << "\n";
    }

    return 0;
}