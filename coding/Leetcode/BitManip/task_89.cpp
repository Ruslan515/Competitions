// https://leetcode.com/problems/gray-code/description/
// Created by ruslan515 on 17.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gray(int n, int depth, vector<int> answer) {
        int t = (1 << (depth - 1));
        if (depth == 0) {
            answer[0] = 0;
        } else {
            for (int i = 0; i < t; ++i) {
                answer[t + i] = answer[t - i - 1] + (1 << (depth - 1));
            }
        }
        if (depth != n) {
            gray(n, depth + 1, answer);
        }
    }

    vector<int> grayCode(int n) {
        vector<int> answer(pow(2, n));
        gray(n, n, answer);
        return answer;
    }
};

int main() {
    vector<int> answer;
    int n;
    Solution solve;

    n = 2;
    answer = {0, 1, 3, 2};
    assert(solve.grayCode(n) == answer);

    n = 1;
    answer = {0, 1};
    assert(solve.grayCode(n) == answer);

    return 0;
}