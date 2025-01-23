// https://leetcode.com/contest/weekly-contest-387/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
// Created by omega515 on 03.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>> &grid, int k) {
        int answer = 0;
        if (grid[0][0] > k) {
            return answer;
        }
        answer = 1;
        int n = grid.size();
        int m = grid[0].size();


        // first row
        int i = 0;
        int j;
        int sums = grid[0][0];
        for (j = 1; j < m; ++j) {
            sums += grid[i][j];
            if (sums > k) {
                break;
            }
            ++answer;
        }

        // first col
        j = 0;
        sums = grid[0][0];
        for (i = 1; i < n; ++i) {
            sums += grid[i][j];
            if (sums > k) {
                break;
            }
            ++answer;
        }

        sums = grid[0][0];
        for (int z = 1; z < min(n, m); ++z) {
            sums += grid[z][z];
            if (sums > k) {
                break;
            }
            for (j = 0; j < z; ++j) {
                sums += grid[z][j];
            }
            if (sums > k) {
                break;
            }
            for (i = 0; i < z; ++i) {
                sums += grid[i][z];
            }
            if (sums > k) {
                break;
            }
            ++answer;
        }
        if (m > n) {
            // sum cols
            for (int z = n; z < m; ++z) {
                for (int i = 0; i < n; ++i) {
                    sums += grid[i][z];
                }
                if (sums > k) {
                    break;
                }
                ++answer;
            }
        } else {
            // sum rows
            for (int z = m; z < n; ++z) {
                for (int i = 0; i < m; ++i) {
                    sums += grid[z][i];
                }
                if (sums > k) {
                    break;
                }
                ++answer;
            }

        }

        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    int k;
    int answer;
    Solution solve;

    grid = {{9,  9, 3},
            {1,  1, 7},
            {8,  4, 6},
            {10, 3, 2},
            {2,  3, 3}};
    k = 49;
    answer = 12;
    assert(answer == solve.countSubmatrices(grid, k));

    grid = {{7,  7, 10, 9},
            {10, 5, 10, 3}};
    k = 54;
    answer = 7;
    assert(answer == solve.countSubmatrices(grid, k));

    grid = {{7, 6, 3},
            {6, 6, 1}}, k = 6;
    answer = 0;
    assert(answer == solve.countSubmatrices(grid, k));

    grid = {{7, 6, 3},
            {6, 6, 1}}, k = 7;
    answer = 1;
    assert(answer == solve.countSubmatrices(grid, k));


    grid = {{7, 6, 3},
            {6, 6, 1}}, k = 18;
    answer = 4;
    assert(answer == solve.countSubmatrices(grid, k));

    grid = {{7, 2, 9},
            {1, 5, 0},
            {2, 6, 6}}, k = 20;
    answer = 6;
    assert(answer == solve.countSubmatrices(grid, k));


    return 0;
}

