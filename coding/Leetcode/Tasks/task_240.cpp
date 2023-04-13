// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Created by ruslan515 on 11.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool searchSubMatrix(vector<vector<int>> &matrix, int target, int x1, int y1, int x2, int y2) {
        int m = x2 - x1;
        int n = y2 - y1;
        int row = m / 2;
        int col = n / 2;
        int temp = matrix[row][col];
        if (temp == target) {
            return true;
        }
        bool t2 = searchSubMatrix(matrix, target, x1, row, n, col);
        if (t2) {
            return true;
        }
        bool t3 = searchSubMatrix(matrix, target, col, y1, n, col);
        if (t3) {
            return true;
        }
        if (temp < target) {
            bool t1 = searchSubMatrix(matrix, target, x1, y1, col, row);
            if (t1) {
                return true;
            }
        } else {
            bool t4 = searchSubMatrix(matrix, target, col, row, x2, y2);
            if (t4) {
                return true;
            }
        }
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        bool answer = searchSubMatrix(matrix, target, 0, 0, m, n);

        return answer;
    }
};

void read_data(vector<vector<int>> &matrix, int &target) {
    cin >> target;
    int m, n;
    cin >> m >> n;
    int temp;
    for (int i = 0; i < m; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }
    return;
}

int main() {
    vector<vector<int>> matrix;
    int target;
    read_data(matrix, target);
    Solution solve;

    cout << solve.searchMatrix(matrix, target);

    return 0;
}