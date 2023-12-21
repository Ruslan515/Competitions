// https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19
// Created by omega515 on 19.12.23.
//

#include <bits/stdc++.h>

#include <bits/stdc++.h>zz

using namespace std;

class Solution {
public:
    int getAvg(vector<vector<int>> &img, int i, int j, int m, int n) {
        int avg = img[i][j];
        vector<pair<int, int>> diff = {
                {-1, 1},
                {-1, 0},
                {-1, -1},
                {1,  1},
                {1,  0},
                {1,  -1},
                {0,  -1},
                {0,  1}
        };
        int newX, newY;
        int count = 1;
        for (auto yx: diff) {
            auto [y, x] = yx;
            newY = i + y;
            newX = j + x;
            if ((newY >= 0 && newY < m) && (newX >= 0 && newX < n)) {
                avg += img[newY][newX];
                ++count;
            }
        }
        avg = floor(avg / count);
        return avg;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));
        int val;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                val = getAvg(img, i, j, m, n);
                answer[i][j] = val;
            }
        }

        return answer;
    }
};
