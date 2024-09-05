//
// Created by omega515 on 03.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(
            vector<int> &nums, vector<int> &current,
            vector<vector<int>> &answer,
            int k, int idx
    ) {
        if (current.size() == k) {
            answer.push_back(current);
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtracking(nums, current, answer, k, i + 1);
            current.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> answer;
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        vector<int> current = {};
        backtracking(nums, current, answer, k, 0);

        return answer;
    }
};

int main() {
    int n, k;
    vector<vector<int>> answer;
    Solution solve;

    n = 4, k = 2;
    answer = {{1, 2},
              {1, 3},
              {1, 4},
              {2, 3},
              {2, 4},
              {3, 4}};
    assert(answer == solve.combine(n, k));

    n = 1, k = 1;
    answer = {{1}};
    assert(answer == solve.combine(n, k));

    return 0;
}
