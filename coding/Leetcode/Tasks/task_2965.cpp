// https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06
// Created by omega515 on 06.03.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        unordered_set<int> set1;
        int a = -1, b;
        int n = grid.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (set1.find(grid[i][j]) != set1.end()) {
                    a = grid[i][j];
                } else {
                    set1.insert(grid[i][j]);
                }
            }
        }
        for (int i = 1; i <= n * n; ++i) {
            if (set1.find(i) == set1.end()) {
                b = i;
                break;
            }
        }
        vector<int> answer = {a, b};

        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    vector<int> answer;
    Solution solve;

    grid = {{1, 3},
            {2, 2}};
    answer = {2, 4};
    assert(answer == solve.findMissingAndRepeatedValues(grid));

    grid = {{9, 1, 7},
            {8, 9, 2},
            {3, 4, 6}};
    answer = {9, 5};
    assert(answer == solve.findMissingAndRepeatedValues(grid));

    return 0;
}

