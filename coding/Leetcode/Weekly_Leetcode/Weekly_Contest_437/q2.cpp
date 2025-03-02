// https://leetcode.com/contest/weekly-contest-437/problems/eat-pizzas/?slug=find-special-substring-of-length-k&tab=description&region=global_v2
// Created by omega515 on 16.02.25.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long maxWeight(vector<int> &pizzas) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ll answer = 0;
        int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        int d = n / 4;
        if (d == 2) {
            answer += pizzas[7] + pizzas[5];
            return answer;
        }

        int k = d / 2 + d % 2;
        int t = d - k;
        ll tmp;
        for (int i = 0; i < k; ++i) {
            tmp = (ll) pizzas[n - 1 - i];
            answer += tmp;
        }
        for (int i = 0; i < t; ++i) {
            tmp = (ll) pizzas[n - 1 - k - i * 2 - 1];
            answer += tmp;
        }


        return answer;
    }
};

int main() {
    vector<int> pizzas;
    ll answer;
    Solution solve;

    pizzas = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    answer = 32;
    assert(answer == solve.maxWeight(pizzas));

    pizzas = {1, 2, 3, 4, 5, 6, 7, 8};
    answer = 14;
    assert(answer == solve.maxWeight(pizzas));

    pizzas = {2, 1, 1, 1, 1, 1, 1, 1};
    answer = 3;
    assert(answer == solve.maxWeight(pizzas));


    return 0;
}
