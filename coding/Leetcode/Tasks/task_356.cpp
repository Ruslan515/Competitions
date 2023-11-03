// https://leetcode.com/problems/line-reflection/
// Created by ruslan515 on 27.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isReflected(vector<vector<int>> &points) {
        bool answer = false;
        int n = points.size();
        if (n == 1) {
            return true;
        }
        int minX = INT_MAX, maxX = -INT_MAX;
        for (auto point: points) {
            int x = point[0];
            minX = min(minX, x);
            maxX = max(maxX, x);
        }
        int xMid = (minX + maxX) / 2;

        for (int i = 0; i < n; ++i) {
            vector<int> current = points[i];
            int x = current[0];
            int y = current[1];
            int targetX, targetY = y;
            if (2 * x != (minX + maxX)) {
                targetX = (minX + maxX) - x;
            } else {
                continue;
            }
            int xN, yN;
            bool label = false;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    vector<int> p = points[j];
                    xN = p[0];
                    yN = p[1];
                    if (xN == targetX && yN == targetY) {
                        label = true;
                        break;
                    }
                }
            }
            if (!label) {
                return answer;
            }
        }

        answer = true;
        return answer;
    }
};

int main() {
    vector<vector<int>> points;
    bool answer;
    Solution solve;

    points = {{0, 0},
              {1, 0}};
    answer = true;
    assert(answer == solve.isReflected(points));

    points = {{0, 0}};
    answer = true;
    assert(answer == solve.isReflected(points));

    points = {{1,  1},
              {-1, 1}};
    answer = true;
    assert(answer == solve.isReflected(points));

    points = {{1,  1},
              {-1, -1}};
    answer = false;
    assert(answer == solve.isReflected(points));

    return 0;
}