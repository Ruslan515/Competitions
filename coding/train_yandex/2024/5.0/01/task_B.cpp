// https://contest.yandex.ru/contest/59539/problems/B/
// Created by ruslan515 on 04.03.2024
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int g1, g2, g11, g22, home;
    char ch;
    cin >> g1 >> ch >> g2 >> g11 >> ch >> g22 >> home;
    int answer = 0;
    int sums1, sums2;
    sums1 = g1 + g11;
    sums2 = g2 + g22;
    if (sums1 > sums2) {
        answer = 0;
    } else if (sums1 == sums2) {
        if (home == 1) {
            if (g11 <= g2) {
                answer = 1;
            } else if (g11 > g2) {
                answer = 0;
            }
        } else {
            if (g1 <= g22) {
                answer = 1;
            } else {
                answer = 0;
            }

        }

    } else {
        int d = sums2 - sums1;
        if (home == 1) {
            if (g11 + d > g2) {
                answer = d;
            } else {
                answer = d + 1;
            }

        } else {
            if (g1 <= g22) {
                answer = d + 1;
            } else {
                answer = d;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
