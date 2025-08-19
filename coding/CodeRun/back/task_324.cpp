// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/trading-ya-intern?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=6
// Created by ruslan515 on 20.06.23.
//

#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    long long answer = 0;
    int i = 0;
    int diff;
    int minI = min(a.size(), b.size());
    while (i < minI && b[i] >= a[i]) {
        diff = (long long)b[i] - a[i];
        answer += diff;
        ++i;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.push_back(temp);
    }

    for (int i = 0; i < m; ++i) {
        cin >> temp;
        b.push_back(temp);
    }

    long long answer = solve(a, b);
    cout << answer << "\n";

    return 0;
}