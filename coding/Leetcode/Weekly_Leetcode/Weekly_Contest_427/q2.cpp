// https://leetcode.com/contest/weekly-contest-427/problems/maximum-area-rectangle-with-point-constraints-i/description/
// Created by omega515 on 08.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = points.size();
        set<pair<int, int>> pointSet;
        for (const auto& point : points) {
            pointSet.insert({point[0], point[1]});
        }

        int maxArea = -1;

        // Перебираем все пары точек как потенциальные противоположные углы
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // Проверяем, образуют ли точки прямоугольник
                if (x1 != x2 && y1 != y2) {
                    // Проверяем существование других двух углов
                    pair<int, int> p3 = {x1, y2};
                    pair<int, int> p4 = {x2, y1};

                    if (pointSet.count(p3) && pointSet.count(p4)) {
                        // Проверяем, нет ли точек на сторонах или внутри прямоугольника
                        bool valid = true;
                        int minX = min(x1, x2);
                        int maxX = max(x1, x2);
                        int minY = min(y1, y2);
                        int maxY = max(y1, y2);

                        for (const auto& p : pointSet) {
                            int x = p.first, y = p.second;
                            // Проверяем точки, которые не являются углами прямоугольника
                            if ((x != x1 || y != y1) && (x != x2 || y != y2) &&
                                (x != p3.first || y != p3.second) && (x != p4.first || y != p4.second)) {
                                if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
                                    valid = false;
                                    break;
                                }
                            }
                        }

                        if (valid) {
                            int area = (maxX - minX) * (maxY - minY);
                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};



int main() {
    vector<vector<int>> points;
    int answer;
    Solution solve;

    points = {{1, 1},
              {1, 3},
              {3, 1},
              {3, 3}};
    answer = 4;
    assert(answer == solve.maxRectangleArea(points));

    points = {{1, 1},
              {1, 3},
              {3, 1},
              {3, 3},
              {2, 2}};
    answer = -1;
    assert(answer == solve.maxRectangleArea(points));

    points = {{1, 1},
              {1, 3},
              {3, 1},
              {3, 3},
              {1, 2},
              {3, 2}};
    answer = 2;
    assert(answer == solve.maxRectangleArea(points));

    return 0;
}
