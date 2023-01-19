// https://leetcode.com/problems/reshape-the-matrix/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 19.01.23.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int idx = i * c + j;
                int x, y;
                x = idx / n;
                y = idx % n;
                ans[i][j] = mat[x][y];
            }
        }
        return ans;

    }
};

void read_data(vector<vector<int>>& mat, int& r, int& c) {
    int m, n;
    cin >> m >> n;
    cin >> r >> c;
    int a, b;
    for (int i = 0; i < m; ++i) {
        vector<int> t;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            t.push_back(a);
        }
        mat.push_back(t);
    }
    return;
}

int main() {
    vector<vector<int>> mat;
    int r;
    int c;
    read_data(mat, r, c);
    Solution solve;
    vector<vector<int>> ans = solve.matrixReshape(mat, r, c);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}