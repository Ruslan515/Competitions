// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/a-1-find-most-frequent?currentPage=2&difficulty=EASY&pageSize=10&rowNumber=12
// Created by ruslan515 on 20.06.23.
//

#include <bits/stdc++.h>

const int inf = INT32_MAX;
using namespace std;

int solve(vector<int> a) {
    int answer = -1;
    map<int, int> cnt;
    for(int num: a) {
        ++cnt[num];
    }

    int countMax = -1;
    for(pair<int, int> el: cnt) {
        if (el.second >= countMax && el.first > answer) {
            answer = el.first;
            countMax = el.second;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.push_back(temp);
    }


    int answer = solve(a);
    cout << answer << "\n";

    return 0;
}