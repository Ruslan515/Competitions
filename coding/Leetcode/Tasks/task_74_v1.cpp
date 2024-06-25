// https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 20.06.24.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        bool answer = false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        int mid, i, j, val;
        while (left <= right) {
            mid = left + (right - left) / 2;
            i = mid / n;
            j = mid - (i * n);
            val = matrix[i][j];
            if (target == val) {
                answer = true;
                break;
            } else if (target < val) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> matrix;
    int target;
    bool answer;
    Solution solve;

    matrix = {{1,  3,  5,  7},
              {10, 11, 16, 20},
              {23, 30, 34, 60}}, target = 3;
    answer = true;
    assert(answer == solve.searchMatrix(matrix, target));

    matrix = {{1,  3,  5,  7},
              {10, 11, 16, 20},
              {23, 30, 34, 60}}, target = 13;
    answer = false;
    assert(answer == solve.searchMatrix(matrix, target));

    return 0;
}

