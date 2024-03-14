// https://contest.yandex.ru/contest/59539/problems/E/
// Created by ruslan515 on 08.03.2024
//

#include<bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k, d;
    cin >> n >> k >> d;
    string n_low = to_string(n), n_higth = to_string(n);
    n_low += "0";
    n_higth += "9";
    long long n_low_int = stoi(n_low);
    long long n_hight_int = stoi(n_higth);
    long long dd = n_low_int / k;
    long long low = k * dd;
    long long hight = k * (d + 1);
    if (low >= n_low_int && low <= n_hight_int) {
        cout << low;
    } else if (hight >= n_low_int && hight <= n_hight_int) {
        cout << hight;
    } else {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < d - 1; ++i) {
        cout << 0;
    }
    cout << "\n";

    return 0;
}
