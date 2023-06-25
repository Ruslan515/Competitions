// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/checkers?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=7
// Created by ruslan515 on 23.06.23.
//

#include <bits/stdc++.h>

using namespace std;

string solve(
        set<pair<int, int>> first,
        set<pair<int, int>> last,
        int n, int m, string who
) {
    string answer = "Yes";
    vector<pair<int, int>> direction = {
            {-1, 1},
            {-1, -1},
            {1,  -1},
            {1,  1},
    };

    int x, y, dx, dy, nx, ny, n2x, n2y;
    for (pair<int, int> el: first) {
        x = el.first;
        y = el.second;
        for (auto dxdy: direction) {
            dx = dxdy.first;
            dy = dxdy.second;
            nx = x + dx;
            ny = y + dy;
            pair<int, int> t = make_pair(nx, ny);
            if (last.find(t) != last.end()) {
                n2x = nx + dx;
                n2y = ny + dy;
                pair<int, int> next = make_pair(n2x, n2y);
                if (
                        n2x >= 0 && n2x < n && n2y>= 0 && n2y < m && first.find(next) == first.end() && last.find(next) == last.end()
                        ) {
                    return answer;
                }
            }

        }

    }

    answer = "No";
    return answer;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int w, b;
    cin >> w;
    set<pair<int, int>> white, black;
    int x, y;
    for (int i = 0; i < w; ++i) {
        cin >> x >> y;
        white.insert({--x, --y});
    }

    cin >> b;
    for (int i = 0; i < b; ++i) {
        cin >> x >> y;
        black.insert({--x, --y});
    }

    string who;
    cin >> who;

    string answer;
    if (who == "white") {
        answer = solve(white, black, n, m, who);
    } else {
        answer = solve(black, white, n, m, who);
    }

    cout << answer << "\n";

    return 0;
}