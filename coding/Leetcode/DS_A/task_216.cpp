// https://leetcode.com/problems/combination-sum-iii/description/
// Created by omega515 on 15.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(
            vector<vector<int>> &answer,
            vector<int> &current, int n, int k, int currentSum, int idx
    ) {
        if (current.size() == k && currentSum == n) {
            answer.push_back(current);
            return;
        }

        for (int i = idx; i <= 9; ++i) {
            int tmp = currentSum + i;
            bool check = tmp <= n;
            if (check) {
                current.push_back(i);
                backtracking(answer, current, n, k, tmp, i + 1);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> answer;
        int minSum = 0, maxSum = 0;
        for (int i = 1; i <= k; ++i) {
            minSum += i;
            maxSum += 10 - i;
        }
        bool check = (n >= minSum) && (n <= maxSum);
        if (check) {
            vector<int> current;
            int currentSum = 0;
            backtracking(answer, current, n, k, currentSum, 1);
        }

        return answer;
    }
};

int main() {
    int n, k;
    vector<vector<int>> answer;
    Solution solve;

    k = 3, n = 7;
    answer = {{1, 2, 4}};
    assert(answer == solve.combinationSum3(k, n));

    k = 3, n = 9;
    answer = {{1, 2, 6},
              {1, 3, 5},
              {2, 3, 4}};
    assert(answer == solve.combinationSum3(k, n));

    k = 4, n = 1;
    answer = {};
    assert(answer == solve.combinationSum3(k, n));

    return 0;
}
