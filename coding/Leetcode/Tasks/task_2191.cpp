// https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24
// Created by omega515 on 24.07.24.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convert(vector<int> &mapping, int num) {
        if (num == 0) {
            return mapping[0];
        }
        int answer = 0;

        int d, k;
        int t = 1;
        while (num) {
            d = num % 10;
            k = mapping[d];
            k *= t;
            answer += k;
            t *= 10;
            num /= 10;
        }

        return answer;
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        struct myCompVec {
            bool operator()(
                    vector<int> const &a,
                    vector<int> const &b
            ) {
                return a[0] != b[0] ? a[0] > b[0] : a[1] > b[1];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, myCompVec> pq;
        int n = nums.size();
        int k;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            k = convert(mapping, x);
            pq.push({k, i, nums[i]});
        }
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            v = pq.top();
            pq.pop();
            k = v[2];
            answer.push_back(k);
        }

        return answer;
    }
};

int main() {
    vector<int> mapping, nums;
    vector<int> answer;
    Solution solve;

    mapping = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    answer = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    assert(answer == solve.sortJumbled(mapping, nums));

    mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6}, nums = {991, 338, 38};
    answer = {338, 38, 991};
    assert(answer == solve.sortJumbled(mapping, nums));

    mapping = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, nums = {0, 999999999};
    answer = {0, 999999999};
    assert(answer == solve.sortJumbled(mapping, nums));

    mapping = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, nums = {789, 456, 123};
    answer = {123, 456, 789};
    assert(answer == solve.sortJumbled(mapping, nums));

    return 0;
}
