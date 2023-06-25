// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/server-error?currentPage=2&pageSize=10&rowNumber=11
// Created by ruslan515 on 11.06.23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    double pA = 0;
    vector<double> ab(n);
    int ai, bi;
    for (int i = 0; i < n; ++i) {
        cin >> ai >> bi;
        ab[i] = (double) ai * bi * 1.0 / 100;
        pA += ab[i];
    }
    for (int i = 0; i < n; ++i) {
        double temp = ab[i] / pA;
        cout << setprecision(11) << temp << '\n';
    }

    return 0;
}