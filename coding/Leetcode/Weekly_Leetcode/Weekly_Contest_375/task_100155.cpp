// https://leetcode.com/contest/weekly-contest-375/problems/double-modular-exponentiation/
// Created by omega515 on 10.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
        vector<int> answer;
        int n = variables.size();
        long long a, b, c, m;
        long long res;
        vector<int> var;
        for (int i = 0; i < n; ++i) {
            var = variables[i];
            a = var[0];
            b = var[1];
            c = var[2];
            m = var[3];
            res = pow((a % 10), b * c);
            res %= m;
            if (res == target) {
                answer.push_back(i);
            }

        }

        return answer;
    }
};

int main() {
    vector<vector<int>> variables;
    int target;
    vector<int> answer;
    Solution solve;

    variables = {{2, 3, 3, 10},
                 {3, 3, 3, 1},
                 {6, 1, 1, 4}}, target = 2;
    answer = {0, 2};
    assert(answer == solve.getGoodIndices(variables, target));

    variables = {{39, 3, 1000, 1000}}, target = 17;
    answer = {};
    assert(answer == solve.getGoodIndices(variables, target));

    return 0;
}

