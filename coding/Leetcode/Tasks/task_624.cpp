// https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 22.06.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int m = arrays.size();
        int first = arrays[0].size();
        int second = arrays[1].size();
        int minVal = arrays[0][0], maxVal = arrays[0][arrays[0].size() - 1];

        int n;
        int currMin, currMax;
        for (int i = 1; i < m; ++i) {
            currMin = arrays[i][0];
            n = arrays[i].size();
            currMax = arrays[i][n - 1];
            answer = max(
                    answer,
                    max(
                            abs(arrays[i][n - 1] - minVal),
                            abs(arrays[i][0] - maxVal)
                    )
            );
            maxVal = max(maxVal, currMax);
            minVal = min(minVal, currMin);
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> arrays;
    int answer;
    Solution solve;

    arrays = {{1, 4},
              {0, 5}};
    answer = 4;
    assert(answer == solve.maxDistance(arrays));

    arrays = {{-1, -1, -1},
              {-2, -2, -1}};
    answer = 1;
    assert(answer == solve.maxDistance(arrays));

    arrays = {{1, 2, 3},
              {4, 5},
              {1, 2, 3}};
    answer = 4;
    assert(answer == solve.maxDistance(arrays));

    arrays = {{1},
              {1}};
    answer = 0;
    assert(answer == solve.maxDistance(arrays));

    return 0;
}

