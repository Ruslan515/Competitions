// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=daily-question&envId=2023-12-21
// Created by omega515 on 21.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points) {
        int answer = 0;
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[0] < b[0];
             });
        int maxDiff = 0;
        int n = points.size();
        for (int i = 0; i < n - 1; ++i) {
            int diff = points[i + 1][0] - points[i][0];
            maxDiff = max(diff, maxDiff);
        }

        answer = maxDiff;
        return answer;
    }
};

int main() {
    vector<vector<int>> points;
    int answer;
    Solution solve;

    points = {{8, 7},
              {9, 9},
              {7, 4},
              {9, 7}};
    answer = 1;
    assert(answer == solve.maxWidthOfVerticalArea(points));

    points = {{3, 1},
              {9, 0},
              {1, 0},
              {1, 4},
              {5, 3},
              {8, 8}};
    answer = 3;
    assert(answer == solve.maxWidthOfVerticalArea(points));

    return 0;
}