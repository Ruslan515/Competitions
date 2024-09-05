// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01
// Created by omega515 on 01.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> answer;
        int size = original.size();
        if (size != m * n) {
            return answer;
        }

        for (int i = 0; i < m; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                row.push_back(original[i * n + j]);
            }
            answer.push_back(row);
        }

        return answer;
    }
};

int main() {
    vector<int> original;
    int m, n;
    vector<vector<int>> answer;
    Solution solve;

    original = {1, 2, 3, 4}, m = 2, n = 2;
    answer = {{1, 2},
              {3, 4}};
    assert(answer == solve.construct2DArray(original, m, n));

    original = {1, 2, 3}, m = 1, n = 3;
    answer = {{1, 2, 3}};
    assert(answer == solve.construct2DArray(original, m, n));

    original = {1, 2}, m = 1, n = 1;
    answer = {};
    assert(answer == solve.construct2DArray(original, m, n));

    return 0;
}
