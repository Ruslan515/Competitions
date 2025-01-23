// https://leetcode.com/contest/weekly-contest-362/problems/points-that-intersect-with-cars/
// Created by ruslan515 on 10.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>> &nums) {
        int answer = 0;
        set<int> setNums;
        int x, y;
        for (auto num: nums) {
            x = num[0];
            y = num[1];
            for (int i = x; i <= y; ++i) {
                setNums.insert(i);
            }
        }
        answer = setNums.size();

        return answer;
    }
};


int main() {
    vector<vector<int>> nums;
    int answer;
    Solution solve;

    nums = {{3, 6},
            {1, 5},
            {4, 7}};
    answer = 7;
    assert(answer == solve.numberOfPoints(nums));

    nums = {{1, 3},
            {5, 8}};
    answer = 7;
    assert(answer == solve.numberOfPoints(nums));

    return 0;
}

