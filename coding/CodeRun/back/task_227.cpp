// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/library?currentPage=1&difficulty=MEDIUM&pageSize=10&rowNumber=3
// Created by ruslan515 on 21.06.23.
//

#include <bits/stdc++.h>

using namespace std;

void solve(int k, int m, int d) {
    int count = 1;
    int morning = m + k;
    int evening = 0;
    int answer = 0;

    while (count <= morning) {
        evening = morning - count;
        ++count;
        ++d;
        d %= 8;
        if (d != 6 && d != 7) {
            morning = evening + k;
        } else {
            morning = evening;
        }
        ++answer;
    }

    cout << answer << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, m, d;
    cin >> k >> m >> d;
    solve(k, m, d);

    return 0;
}