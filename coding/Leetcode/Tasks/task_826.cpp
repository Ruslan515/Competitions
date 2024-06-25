// https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18
// Created by omega515 on 18.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        int answer = 0;
//        sort(worker.begin(), worker.end(), greater<>());
//        int max_w = worker[0];
        int max_w = *max_element(worker.begin(), worker.end());
        vector<pair<int, int>> v;
        int n = difficulty.size();
        int diff, prof;
        for (int i = 0; i < n; ++i) {
            diff = difficulty[i];
            if (diff <= max_w) {
                v.push_back(make_pair(profit[i], difficulty[i]));
            }
        }
        if (v.size() == 0) {
            return answer;
        }
        sort(v.begin(), v.end(), greater<>());

        int m = worker.size();
        for (int i = 0; i < m; ++i) {
            int w = worker[i];
            for (int j = 0; j < v.size(); ++j) {
                pair<int, int> p = v[j];
                prof = p.first;
                diff = p.second;
                if (w >= diff) {
                    answer += prof;
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {
    vector<int> difficulty, profit, worker;
    int answer;
    Solution solve;

    difficulty = {28, 42, 61, 79, 82}, profit = {3, 41, 62, 64, 83}, worker = {1, 4, 25, 7, 64};
    answer = 62;
    assert(answer == solve.maxProfitAssignment(difficulty, profit, worker));

    difficulty = {68, 35, 52, 47, 86}, profit = {67, 17, 1, 81, 3}, worker = {92, 10, 85, 84, 82};
    answer = 324;
    assert(answer == solve.maxProfitAssignment(difficulty, profit, worker));

    difficulty = {2, 4, 6, 8, 10, 10}, profit = {10, 20, 30, 40, 50, 77}, worker = {4, 5, 6, 7};
    answer = 100;
    assert(answer == solve.maxProfitAssignment(difficulty, profit, worker));

    difficulty = {85, 47, 57}, profit = {24, 66, 99}, worker = {40, 25, 25};
    answer = 0;
    assert(answer == solve.maxProfitAssignment(difficulty, profit, worker));

    return 0;
}
