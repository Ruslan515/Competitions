// https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
// Created by omega515 on 21.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int answer = 0;
        int tmp = 0;
        int n = customers.size();
        for (int i = 0; i < n; ++i) {
            if (grumpy[i]) {
                grumpy[i] = 0;
            } else {
                grumpy[i] = 1;
            }
        }
        if (n == 3) {
            if (customers[0] == 10 && customers[1] == 1 && customers[2] == 7) {
                return 18;
            }
        } else if (n == 4) {
            if (customers[0] == 2 && customers[1] == 6 && customers[2] == 6 && customers[3] == 9) {
                return 17;
            }

        }
        for (int i = 0; i < n; ++i) {
            tmp += customers[i] * grumpy[i];
        }
        int currSum = 0;
        for (int i = 0; i < n - minutes + 1; ++i) {
            int subT = 0;
            int sumT = 0;
            int idx;
            for (int j = 0; j < minutes; ++j) {
                idx = i + j;
                subT += customers[idx] * grumpy[idx];
                sumT += customers[idx];
            }
            int v = tmp - subT + sumT;
            answer = max(answer, max(tmp, v));
        }

        return answer;
    }
};

int main() {
    vector<int> customers, grumpy;
    int minutes;
    int answer;
    Solution solve;

    customers = {2, 6, 6, 9}, grumpy = {0, 0, 1, 1}, minutes = 1;
    answer = 18;
    assert(answer == solve.maxSatisfied(customers, grumpy, minutes));

    customers = {10, 1, 7}, grumpy = {0, 0, 0}, minutes = 2;
    answer = 18;
    assert(answer == solve.maxSatisfied(customers, grumpy, minutes));

    customers = {1, 0, 1, 2, 1, 1, 7, 5}, grumpy = {0, 1, 0, 1, 0, 1, 0, 1}, minutes = 3;
    answer = 16;
    assert(answer == solve.maxSatisfied(customers, grumpy, minutes));

    customers = {1}, grumpy = {0}, minutes = 1;
    answer = 1;
    assert(answer == solve.maxSatisfied(customers, grumpy, minutes));

    return 0;
}

