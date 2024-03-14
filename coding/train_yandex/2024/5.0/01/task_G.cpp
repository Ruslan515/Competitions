// https://contest.yandex.ru/contest/59539/problems/G/
// Created by ruslan515 on 07.03.2024
//

#include<bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, y, p, count_p = 0, countAttackBarracks = 0;
    cin >> x >> y >> p;
    int answer = 1;
    while (true) {
        // 1.
        if (count_p == 0) {
            y -= min(x, y);
            if (y == 0) {
                break;
            }
        } else {
            countAttackBarracks = min(x, y);
            x -= countAttackBarracks;
            y -= countAttackBarracks;
        }

        ++answer;
    }

    cout << answer << "\n";


    return 0;
}
