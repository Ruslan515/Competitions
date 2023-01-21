// https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 21.01.23.
//

#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int size = 9;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool answer = false;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; ++i) {
            int start = matrix[i][0];
            int end = matrix[i][m - 1];
            if (target >= start && target <= end) {
                for (int num: matrix[i]) {
                    if (num == target)
                        return true;
                }
            }
        }

        return answer;
    }
};

void read_data(vector<vector<int>>& matrix, int& target) {
    cin >> target;
    int m, n;
    cin >> m >> n;
    int temp;
    for(int i = 0; i < m; ++i) {
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