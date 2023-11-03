// https://contest.yandex.ru/contest/53027/problems/
// Created by ruslan515 on 03.11.23.
//

//#include <iostream>
//#include <vector>

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int l, int r) {
    int answer = -1;
    int currMin = 1001;
    for (int i = l; i <= r; ++i) {
        currMin = min(currMin, a[i]);
    }
    for (int i = l; i <= r; ++i) {
        if (a[i] != currMin) {
            return a[i];
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l, r, answer;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        answer = solve(a, l, r);
        if (answer == -1) {
            cout << "NOT FOUND\n";
        } else {
            cout << answer << "\n";
        }
    }


    return 0;
}