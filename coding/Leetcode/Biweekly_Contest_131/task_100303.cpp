// https://leetcode.com/contest/biweekly-contest-131/problems/find-occurrences-of-an-element-in-an-array/
// Created by omega515 on 25.05.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x) {
        vector<int> answer;
        vector<int> idx;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == x) {
                idx.push_back(i);
            }
        }
        int size_idx = idx.size();

        int q_size = queries.size();
        for (int i = 0; i < q_size; ++i) {
            if (size_idx == 0) {
                answer.push_back(-1);
            } else {
                int val = queries[i] - 1;
                if (val >= size_idx) {
                    answer.push_back(-1);
                } else {
                    answer.push_back(idx[val]);
                }
            }
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> queries;
    int x;
    vector<int> answer;
    Solution solve;

    nums = {1, 3, 1, 7};
    queries = {1, 3, 2, 4};
    x = 1;
    answer = {0, -1, 2, -1};
    assert(answer == solve.occurrencesOfElement(nums, queries, x));

    nums = {1, 2, 3}, queries = {10}, x = 5;
    answer = {-1};
    assert(answer == solve.occurrencesOfElement(nums, queries, x));


    return 0;
}

