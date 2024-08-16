//
// Created by omega515 on 09.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkMagic(vector<vector<int>> &grid, int startRow, int startCol) {
        bool answer = false;
        unordered_set<int> st;
        int val;
        unordered_set<int> sums;
        int sum;
        for (int i = 0; i < 3; ++i) {
            sum = 0;
            for (int j = 0; j < 3; ++j) {
                val = grid[startRow + i][startCol + j];
                if (val < 1 || val > 9) {
                    return answer;
                }
                if (st.find(val) != st.end()) {
                    return answer;
                }
                st.insert(val);
                sum += val;
            }
            if (sums.size() == 0) {
                sums.insert(sum);
            } else {
                if (sums.find(sum) == sums.end()) {
                    return answer;
                }
            }
        }

        for (int j = 0; j < 3; ++j) {
            sum = 0;
            for (int i = 0; i < 3; ++i) {
                val = grid[startRow + i][startCol + j];
                sum += val;
            }
            if (sums.find(sum) == sums.end()) {
                return answer;
            }
        }

        sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += grid[startRow + i][startCol + i];
        }
        if (sums.find(sum) == sums.end()) {
            return answer;
        }

        sum = grid[startRow + 2][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow][startCol + 2];
        if (sums.find(sum) == sums.end()) {
            return answer;
        }

        answer = true;

        return answer;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int startRow = 0; startRow < row - 2; ++startRow) {
            for (int startCol = 0; startCol < col - 2; ++startCol) {
                if (checkMagic(grid, startRow, startCol)) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};


int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{4, 3, 8, 4},
            {9, 5, 1, 9},
            {2, 7, 6, 2}};
    answer = 1;
    assert(answer == solve.numMagicSquaresInside(grid));

    grid = {{8}};
    answer = 0;
    assert(answer == solve.numMagicSquaresInside(grid));

    return 0;
}
