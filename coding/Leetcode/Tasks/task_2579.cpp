// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05
// Created by omega515 on 05.03.2025.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll coloredCells(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ll answer = 1;
        vector<ll> v(n + 1, 0);
        v[1] = (ll) 1;
        for (int i = 2; i < n + 1; ++i) {
            v[i] = v[i - 1] + (ll) 4 + (ll) 4 * (i - 2);
        }
        answer = v[n];

        return answer;
    }
};

int main() {
    int n;
    ll answer;
    Solution solve;

    n = 1;
    answer = 1;
    assert(answer == solve.coloredCells(n));

    n = 2;
    answer = 5;
    assert(answer == solve.coloredCells(n));

    n = 3;
    answer = 13;
    assert(answer == solve.coloredCells(n));

    n = 4;
    answer = 25;
    assert(answer == solve.coloredCells(n));

    n = 5;
    answer = 25 + 4 + 3 * 4;
    assert(answer == solve.coloredCells(n));

    return 0;
}

