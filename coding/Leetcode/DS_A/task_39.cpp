// https://leetcode.com/problems/combination-sum/description/
// Created by omega515 on 19.09.24.
//

#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int target;
//    set<map<int, int>> st;
//
//    void backtracking(
//            vector<vector<int>> &answer,
//            vector<int> &current,
//            vector<int> &candidates,
//            int currentSum,
//            int idx
//    ) {
//        if (currentSum == this->target) {
//            map<int, int> tmp;
//            for (int num: current) {
//                ++tmp[num];
//            }
//            if (this->st.find(tmp) == this->st.end()) {
//                answer.push_back(current);
//                this->st.insert(tmp);
//                return;
//            }
//        }
//        for (int i = idx; i < candidates.size(); ++i) {
//            int num = candidates[i];
//            if (currentSum + num <= this->target) {
//                current.push_back(num);
//                currentSum += num;
//                backtracking(answer, current, candidates, currentSum, idx);
//                current.pop_back();
//                currentSum -= num;
//            }
//        }
//    }
//
//    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
//        ios_base::sync_with_stdio(false);
//        cin.tie(nullptr);
//        cout.tie(nullptr);
//
//        this->target = target;
//        vector<vector<int>> answer;
//        vector<int> current;
//        int currentSum = 0;
//        backtracking(answer, current, candidates, currentSum, 0);
//
//        return answer;
//    }
//};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); // Optional: for optimizing pruning
        backtrack(result, combination, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, const vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue; // Skip numbers that are too large

            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i); // Not i + 1 because we can reuse the same number
            combination.pop_back(); // Backtrack
        }
    }


};
int main() {
    vector<int> candidates;
    int target;
    vector<vector<int>> answer;
    Solution solve;

    candidates = {2, 3, 6, 7}, target = 7;
    answer = {{2, 2, 3},
              {7}};
    assert(answer == solve.combinationSum(candidates, target));

    candidates = {2, 3, 5}, target = 8;
    answer = {{2, 2, 2, 2},
              {2, 3, 3},
              {3, 5}};
    assert(answer == solve.combinationSum(candidates, target));

    candidates = {2}, target = 1;
    answer = {};
    assert(answer == solve.combinationSum(candidates, target));

    candidates = {7, 3, 2}, target = 18;
    answer = {{7, 7, 2, 2},
              {7, 3, 3, 3, 2},
              {7, 3, 2, 2, 2, 2},
              {3, 3, 3, 3, 3, 3},
              {3, 3, 3, 3, 2, 2, 2},
              {3, 3, 2, 2, 2, 2, 2, 2},
              {2, 2, 2, 2, 2, 2, 2, 2, 2}};
    assert(answer == solve.combinationSum(candidates, target));

    return 0;
}
