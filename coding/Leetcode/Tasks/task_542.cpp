// https://leetcode.com/problems/01-matrix/description/
// Created by ruslan515 on 07.04.23.
//
/*
10 10
1 0 1 1 0 0 1 0 0 1 0 1 1 0 1 0 1 0 1 1 0 0 1 0 1 0 0 1 0 0 1 0 1 0 1 1 1 1 1 1 0 1 0 1 1 0 0 0 0 1 0 0 1 0 1 1 1 0 1 0 0 1 0 1 0 1 0 0 1 1 1 0 0 0 1 1 1 1 0 1 1 1 1 1 1 1 1 0 1 0 1 1 1 1 0 1 0 0 1 1
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));

        vector<pair<int, int>> v = {
                {-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != 0) {
                    int dist = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    bool label = true;
                    while (!q.empty() && label) {
                        int size_q = q.size();
                        for (int k = 0; k < size_q; ++k) {
                            pair<int, int> xy = q.front();
                            q.pop();
                            int x = xy.first;
                            int y = xy.second;
                            int z = 0;
                            for (auto temp: v) {
                                int dx = temp.first;
                                int dy = temp.second;
                                int new_x = x + dx;
                                int new_y = y + dy;
                                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                                    if (mat[new_x][new_y] == 0) {
                                        label = false;
                                        break;
                                    } else {
                                        q.push({new_x, new_y});
                                        ++z;
                                    }
                                }
                            }
                            if (!label && !q.empty()) {
                                for (int ii = 0; ii < z; ++ii) {
                                    q.pop();
                                }
                                ++dist;
                                break;
                            }
                            ++dist;
                        }
                    }

                    answer[i][j] = dist;
                }
            }
        }

        return answer;
    }
};

void read_data(vector<vector<int>> &mat) {
    int m, n;
    cin >> m >> n;
    int a;
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
    read_data(mat);
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cout << mat[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    Solution solve;
    vector<vector<int>> ans = solve.updateMatrix(mat);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}