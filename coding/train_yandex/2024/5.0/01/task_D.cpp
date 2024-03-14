// https://contest.yandex.ru/contest/59539/problems/Dzz/
// Created by ruslan515 on 06.03.2024
//

#include<bits/stdc++.h>

using namespace std;

const int n = 8;

void find_rook(int x1, int y1, vector<vector<int>> &cheese, set<pair<int, int>> &positions) {
    int cnt = 0;
    // ладья
    for (int i = y1 + 1; i < n && cheese[i][x1] == 0; ++i) { // вниз по столбцу
        positions.insert(make_pair(i, x1));
    }
    for (int i = y1 - 1; i >= 0 && cheese[i][x1] == 0; --i) { // вверх по столбцу
        positions.insert(make_pair(i, x1));;
    }

    for (int j = x1 + 1; j < n && cheese[y1][j] == 0; ++j) { // вправо по строке
        positions.insert(make_pair(y1, j));
    }
    for (int j = x1 - 1; j >= 0 && cheese[y1][j] == 0; --j) { // влево по строке
        positions.insert(make_pair(y1, j));
    }
    ++cnt;

}

void find_bishop(int x2, int y2, vector<vector<int>> &cheese, set<pair<int, int>> &positions) {
    int cnt = 0;
    // слон
    for (int i = 1; i < min(n - y2, x2 + 1) && cheese[y2 + i][x2 - i] == 0; ++i) { // влево вниз
        positions.insert(make_pair(y2 + i, x2 - i));
    }
    for (int i = 1; i < min(y2 + 1, x2 + 1) && cheese[y2 - i][x2 - i] == 0; ++i) { // влево вверх
        positions.insert(make_pair(y2 - i, x2 - i));
    }

    for (int i = 1; i < min(n - y2, n - x2) && cheese[y2 + i][x2 + i] == 0; ++i) { // вправо вниз
        positions.insert(make_pair(y2 + i, x2 + i));
    }
    for (int i = 1; i < min(y2 + 1, n - x2) && cheese[y2 - i][x2 + i] == 0; ++i) { // вправо вверх
        positions.insert(make_pair(y2 - i, x2 + i));
    }
    ++cnt;

}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer = n * n;
    vector<string> cheese_str(n);
    for (int i = 0; i < n; ++i) {
        cin >> cheese_str[i];
    }
    vector<vector<int>> cheese(n, vector<int>(n, 0));
    string curr;
    map<char, vector<pair<int, int>>> coordinates;

    for (int i = 0; i < n; ++i) {
        curr = cheese_str[i];
        for (int j = 0; j < n; ++j) {
            char val = curr[j];
            coordinates[val].push_back(make_pair(i, j));
            if (val == 'R') {
                cheese[i][j] = 1;
            } else if (val == 'B') {
                cheese[i][j] = 2;
            }
        }
    }
    set<pair<int, int>> positions;

    map<char, vector<pair<int, int>>>::iterator it = coordinates.begin();
    for (; it != coordinates.end(); ++it) {
        char key = it->first;
        vector<pair<int, int>> pos = it->second;
        if (key == 'R') {
            for (auto yx: pos) {
                auto [y, x] = yx;
                find_rook(x, y, cheese, positions);
                --answer;
            }
        } else if (key == 'B') {
            for (auto yx: pos) {
                auto [y, x] = yx;
                find_bishop(x, y, cheese, positions);
                --answer;
            }

        }

    }


    answer -= positions.size();
    cout << answer << "\n";

    return 0;
}
