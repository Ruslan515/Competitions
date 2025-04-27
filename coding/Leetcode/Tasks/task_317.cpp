// https://leetcode.com/problems/shortest-distance-from-all-buildings/description/?envType=weekly-question&envId=2025-04-01
// Created by omega515 on 05.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

#define pr pair<int, int>

class Solution {
public:
    int shortestDistance(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;

        unordered_set<pair<int, int>> z;
        unordered_set<pr> zeroIdx;


        return answer;
    }
};

int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{1, 0, 2, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0}};
    answer = 7;
    assert(answer == solve.shortestDistance(grid));

    grid = {{1, 0}};
    answer = 1;
    assert(answer == solve.shortestDistance(grid));

    grid = {{1}};
    answer = -1;
    assert(answer == solve.shortestDistance(grid));

    return 0;
}