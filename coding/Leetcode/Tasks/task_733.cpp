// https://leetcode.com/problems/flood-fill/description/
// Created by ruslan515 on 06.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int current_color = image[sr][sc];
        if (current_color == color) {
            return image;
        }
        vector<pair<int, int>> v = {
                {-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}
        };
        int m = image.size();
        int n = image[0].size();
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                pair<int, int> temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                for (auto xy: v) {
                    int dx = xy.first;
                    int dy = xy.second;
                    int new_x = x + dx;
                    int new_y = y + dy;
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                        int temp_color = image[new_x][new_y];
                        if (temp_color == current_color) {
                            q.push({new_x, new_y});
                            image[new_x][new_y] = color;
                        }
                    }
                }

            }
        }
        return image;
    }
};

void read_data(vector<vector<int>> &image, int &sr, int &sc, int &color) {
    int m, n;
    cin >> m >> n;
    cin >> sr >> sc >> color;
    int a;
    for (int i = 0; i < m; ++i) {
        vector<int> t;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            t.push_back(a);
        }
        image.push_back(t);
    }
    return;
}

int main() {
    vector<vector<int>> image;
    int sr, sc, color;
    read_data(image, sr, sc, color);
    Solution solve;
    vector<vector<int>> ans = solve.floodFill(image, sr, sc, color);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}