// https://contest.yandex.ru/contest/59539/problems/C/
// Created by ruslan515 on 05.03.2024
//
/*
 * 7 test. answer == 13024153355
 */

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long  n;
    cin >> n;
    vector<long long > a(n);
    for (long long  i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long  answer = 0;
    long long  p, d, tmp;
    for (long long  i = 0; i < n; ++i) {
        tmp = a[i];
        d = tmp % 4;
        p = tmp / 4;
        if (d == 3) {
            p++;
            answer += p + 1;
        } else {
            answer += p + d;
        }
    }
    cout << answer << "\n";
    
    return 0;
}
