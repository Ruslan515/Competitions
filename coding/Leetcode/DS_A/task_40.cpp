// https://leetcode.com/problems/combination-sum-ii/description/
// Created by omega515 on 24.09.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void backtracking(
            set<vector<int>> &answer,
            vector<int> &current,
            vector<int> &candidates,
            int target,
            int index) {
        if (target == 0) {
            answer.insert(current);
            return;
        }
        int tmp, diff;
        for (int i = index; i < candidates.size(); ++i) {
            tmp = candidates[i];
            diff = target - tmp;
            bool check = i == index || tmp != candidates[i - 1];
            if (diff >= 0 && check) {
                current.push_back(tmp);
                backtracking(answer, current, candidates, diff, i + 1);
                current.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(candidates.begin(), candidates.end());
        set<vector<int>> result;
        vector<int> current;
        backtracking(result, current, candidates, target, 0);
        vector<vector<int>> answer(result.begin(), result.end());


        return answer;
    }


};


int main() {
    vector<int> candidates;
    int target;
    vector<vector<int>> answer;
    Solution solve;

    candidates = {1, 2, 2, 2, 5}, target = 5;
    answer = {
            {1, 2, 2},
            {5}
    };
    assert(answer == solve.combinationSum2(candidates, target));

    candidates = {10, 1, 2, 7, 6, 1, 5}, target = 8;
    answer = {
            {1, 1, 6},
            {1, 2, 5},
            {1, 7},
            {2, 6}
    };
    assert(answer == solve.combinationSum2(candidates, target));

    candidates = {2, 5, 2, 1, 2}, target = 5;
    answer = {
            {1, 2, 2},
            {5}
    };
    assert(answer == solve.combinationSum2(candidates, target));

    return 0;
}
