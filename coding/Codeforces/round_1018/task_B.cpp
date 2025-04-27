// https://codeforces.com/contest/2096/problem/B
// Created by omega515 on 19.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

struct Statement {
    int type; // 0 - нет самозванцев, 1 - есть самозванцы
    int left, right; // диапазон зрителей
};

bool canBeTrue(const vector<Statement> &statements, int l, int r) {
    vector<pair<int, int>> type0; // диапазоны без самозванцев
    vector<pair<int, int>> type1; // диапазоны с самозванцами

    // Разделяем утверждения по типам
    for (int i = l - 1; i < r; i++) {
        if (statements[i].type == 0) {
            type0.push_back({statements[i].left, statements[i].right});
        } else {
            type1.push_back({statements[i].left, statements[i].right});
        }
    }

    // Проверяем противоречия с помощью сканирования
    vector<pair<int, int>> events;

    for (auto &range: type0) {
        events.push_back({range.first, 0}); // начало диапазона типа 0
        events.push_back({range.second, 1}); // конец диапазона типа 0
    }

    for (auto &range: type1) {
        events.push_back({range.first, 2}); // начало диапазона типа 1
        events.push_back({range.second, 3}); // конец диапазона типа 1
    }

    sort(events.begin(), events.end());

    int active0 = 0, active1 = 0;

    for (auto &event: events) {
        if (event.second == 0) active0++;
        else if (event.second == 1) active0--;
        else if (event.second == 2) active1++;
        else active1--;

        // Если есть активные диапазоны обоих типов, то есть противоречие
        if (active0 > 0 && active1 > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<Statement> statements(m);
        for (int i = 0; i < m; i++) {
            cin >> statements[i].type >> statements[i].left >> statements[i].right;
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            if (canBeTrue(statements, l, r)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
