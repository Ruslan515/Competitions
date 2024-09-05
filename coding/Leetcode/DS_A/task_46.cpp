// https://leetcode.com/problems/permutations/description/
// Created by omega515 on 31.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> answer;
        int n = nums.size();
        queue<pair<vector<int>, unordered_set<int>>> q;
        for (int num: nums) {
            unordered_set<int> st{num};
            vector<int> x{num};
            q.push(make_pair(x, st));
        }
        for (int i = 0; i < n - 1; ++i) {
            int size_q = q.size();
            for (int j = 0; j < size_q; ++j) {
                auto [current_v, current_set] = q.front();
                q.pop();
                for (int k = 0; k < n; ++k) {
                    int num = nums[k];
                    if (current_set.find(num) != current_set.end()) {
                        continue;
                    }
                    vector<int> v;
                    copy(current_v.begin(), current_v.end(), back_inserter(v));
                    v.push_back(nums[k]);
                    unordered_set<int> st(v.begin(), v.end());
                    q.push(make_pair(v, st));
                }
            }
        }
        int size_q = q.size();
        for (int i = 0; i < size_q; ++i) {
            answer.push_back(q.front().first);
            q.pop();
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<vector<int>> answer;
    Solution solve;

    nums = {1, 2, 3};
    answer = {{1, 2, 3},
              {1, 3, 2},
              {2, 1, 3},
              {2, 3, 1},
              {3, 1, 2},
              {3, 2, 1}};
    assert(answer == solve.permute(nums));

    nums = {0, 1};
    answer = {{0, 1},
              {1, 0}};
    assert(answer == solve.permute(nums));

    nums = {1};
    answer = {{1}};
    assert(answer == solve.permute(nums));

    return 0;
}
