//https://contest.yandex.ru/contest/59886/problems/C/
// Created by omega515 on 14.03.24.
//

#include<bits/stdc++.h>

using namespace std;

const long long MAX_TEMP_CONST = pow(10, 9) + 1;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    vector<long long> temps(2 * n + 1);
    for (long long i = 0; i < 2 * n + 1; ++i) {
        cin >> temps[i];
    }
    long long b, tMin, tMax, dMin, dMax, left, right;
    cin >> b;
    for (long long k = 0; k < b; ++k) {
        cin >> tMin >> tMax >> dMin >> dMax;
        left = n + dMin;
        right = n + dMax;
        long long min_temp = MAX_TEMP_CONST;
        long long max_temp = -MAX_TEMP_CONST;
        for (long long i = left; i < right + 1; ++i) {
            long long temp = temps[i];
            min_temp = min(min_temp, temp);
            max_temp = max(max_temp, temp);
        }
        bool low = tMin > max_temp;
        bool high = min_temp > tMax;
        if (low || high) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }

    }


    return 0;
}
