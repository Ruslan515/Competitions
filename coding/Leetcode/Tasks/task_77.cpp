// https://leetcode.com/problems/combinations/description/
// Created by ruslan515 on 22.04.23.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>> &answer, vector<int> &b, int idx, int n, int k) {
        int size = b.size();
        if (size == k) {
            answer.push_back(b);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            b.push_back(i);
            backtracking(answer, b, i + 1, n, k);
            b.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> b;
        backtracking(answer, b, 1, n, k);

        return answer;
    }
};

int main() {
    int n, k;
    vector<vector<int>> answer;
    Solution solve;

    n = 4, k = 2;
    answer = {{1, 2},
              {1, 3},
              {1, 4},
              {2, 3},
              {2, 4},
              {3, 4}};
    assert(solve.combine(n, k) == answer);

    n = 1, k = 1;
    answer = {{1}};
    assert(solve.combine(n, k) == answer);

    n = 2, k = 1;
    answer = {{1},
              {2}};
    assert(solve.combine(n, k) == answer);

    return 0;
}