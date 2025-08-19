// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/trading-ya-intern?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=6
// Created by ruslan515 on 20.06.23.
//

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> min_t;
vector<int> max_t;
vector<int> u;
int p;

inline void update(int i) {
    if (u[i]) {
        int l = i << 1;
        int r = l ^ 1;
        min_t[l] = u[i];
        min_t[r] = u[i];
        max_t[l] = u[i];
        max_t[r] = u[i];
        u[l] = u[i];
        u[r] = u[i];
        u[i] = 0;
    }
}

pair<int, int> get(int i, int l, int r, int ll, int rr) {
    if (r <= ll || rr <= l) {
        return make_pair(INT32_MAX, -1);
    }
    if (ll <= l && r <= rr) {
        return make_pair(min_t[i], max_t[i]);
    }
    update(i);
    int m = (l + r) >> 1;
    auto a = get(i << 1, l, m, ll, rr);
    auto b = get((i << 1) ^ 1, m, r, ll, rr);
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void mySet(int i, int l, int r, int ll, int rr, int v) {
    if (r <= ll || rr <= l) {
        return;
    }
    if (ll <= l && r <= rr) {
        min_t[i] = v;
        max_t[i] = v;
        u[i] = v;
        return;
    }
    update(i);
    int m = (l + r) >> 1;
    int a = i << 1;
    int b = (i << 1) ^ 1;
    mySet(a, l, m, ll, rr, v);
    mySet(b, m, r, ll, rr, v);
    min_t[i] = min(min_t[a], min_t[b]);
    max_t[i] = max(max_t[a], max_t[b]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    p = 1;
    while (p < n) {
        p <<= 1;
    }
    min_t.resize(p << 1);
    max_t.resize(p << 1);
    u.resize(p << 1);
    for (int i = 0; i < n; ++i) {
        cin >> min_t[i + p];
        max_t[i + p] = min_t[i + p];
    }
    for (int i = p - 1; i > 0; --i) {
        min_t[i] = min(min_t[i << 1], min_t[(i << 1) ^ 1]);
        max_t[i] = max(max_t[i << 1], max_t[(i << 1) ^ 1]);
    }
    while (q--) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        auto t = get(1, 0, p, --l, r);
        if (t.first == a && t.second == a) {
            mySet(1, 0, p, l, r, b);
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}