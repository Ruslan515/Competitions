// https://leetcode.com/contest/weekly-contest-388/problems/maximize-happiness-of-selected-children/
// Created by omega515 on 10.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        long long answer = 0;
        long long n = happiness.size();
        priority_queue<int> heap(happiness.begin(), happiness.end());
        long long i = 0;
        long long val;
        while (i < k && i < n ) {
            val = heap.top();
            val -= i;
            heap.pop();
            if (val <= 0) {
                break;
            }
            answer += val;
            ++i;
        }

        return answer;
    }
};

int main() {
    vector<int> happiness;
    int k;
    int answer;
    Solution solve;

    happiness = {12,1,42};
    k = 3;
    answer = 53;
    assert(answer == solve.maximumHappinessSum(happiness, k));

    happiness = {1, 2, 3}, k = 2;
    answer = 4;
    assert(answer == solve.maximumHappinessSum(happiness, k));

    happiness = {1, 1, 1, 1}, k = 2;
    answer = 1;
    assert(answer == solve.maximumHappinessSum(happiness, k));

    happiness = {2, 3, 4, 5}, k = 1;
    answer = 5;
    assert(answer == solve.maximumHappinessSum(happiness, k));

    return 0;
}

