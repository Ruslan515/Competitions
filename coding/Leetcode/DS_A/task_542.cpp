// https://leetcode.com/problems/01-matrix/description/
// Created by ruslan515 on 29.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> diff = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1},
    };

    bool check(int x, int y, int n, int m) {
        bool ans = (x >= 0 && x < n) && (y >= 0 && y < m);
        return ans;
    }

    int getDist(int row, int col, vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int dist = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty() && mat[row][col] != 0) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                auto [row, col] = q.front();
                q.pop();
                int newX, newY;
                for (auto dxy: diff) {
                    auto [dx, dy] = dxy;
                    newX = col + dx;
                    newY = row + dy;
                    if (check(newX, newY, n, m)) {
                        int val = mat[newY][newX];
                        if (val == 0) {
                            ++dist;
                            return dist;
                        }
                        q.push(make_pair(newY, newX));
                    }
                }
            }
            dist++;
        }

        return dist;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> answer(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int dist = getDist(i, j, mat);
                answer[i][j] = dist;
            }
        }
        return answer;
    }
};

vector<vector<int>> diffV(vector<vector<int>> v1, vector<vector<int>> v2) {
    int m = v1.size();
    int n = v1[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = abs(v1[i][j] - v2[i][j]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> mat, answer;
    Solution solve;

    mat = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
           {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
           {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
           {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
           {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
           {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
           {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
           {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
           {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
           {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}};
    answer = {{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
              {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
              {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
              {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
              {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
              {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
              {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
              {1, 0, 0, 0, 1, 2, 1, 1, 0, 1},
              {2, 1, 1, 1, 1, 2, 1, 0, 1, 0},
              {3, 2, 2, 1, 0, 1, 0, 0, 1, 1}};

    vector<vector<int>> my = solve.updateMatrix(mat);

    vector<vector<int>> d = diffV(answer, my);

//    assert(answer == solve.updateMatrix(mat));

    mat = {{0, 0, 0},
           {0, 1, 0},
           {0, 0, 0}};
    answer = {{0, 0, 0},
              {0, 1, 0},
              {0, 0, 0}};
    assert(answer == solve.updateMatrix(mat));

    mat = {{0, 0, 0},
           {0, 1, 0},
           {1, 1, 1}};
    answer = {{0, 0, 0},
              {0, 1, 0},
              {1, 2, 1}};
    assert(answer == solve.updateMatrix(mat));

    return 0;
}