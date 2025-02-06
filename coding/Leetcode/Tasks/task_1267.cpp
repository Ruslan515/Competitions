// https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23
// Created by omega515 on 23.01.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    typedef pair<int, int> pr;

    struct pair_hash {
        inline std::size_t operator()(const std::pair<int, int> &v) const {
            return v.first * 31 + v.second;
        }
    };

    int countServers(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_set<pr, pair_hash> setServers;
        int m = grid.size();
        int n = grid[0].size();

        int cnt, val;
        for (int i = 0; i < m; ++i) {
            cnt = 0;
            unordered_set<pr, pair_hash> setRow;
            for (int j = 0; j < n; ++j) {
                val = grid[i][j];
                if (val == 1) {
                    ++cnt;
                    setRow.insert({i, j});
                }
            }
            if (cnt > 1) {
                unordered_set<pr, pair_hash> result;
                for (const auto &item: setRow) {
                    if (setServers.find(item) == setServers.end()) {
                        result.insert(item);
                    }
                }

                int countDiff = result.size();
                answer += countDiff;
                for (const auto &item: result) {
                    setServers.insert(item);
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            cnt = 0;
            unordered_set<pr, pair_hash> setCol;
            for (int i = 0; i < m; ++i) {
                val = grid[i][j];
                if (val == 1) {
                    ++cnt;
                    setCol.insert({i, j});
                }
            }
            if (cnt > 1) {
                unordered_set<pr, pair_hash> result;
                for (const auto &item: setCol) {
                    if (setServers.find(item) == setServers.end()) {
                        result.insert(item);
                    }
                }

                int countDiff = result.size();
                answer += countDiff;
                for (const auto &item: result) {
                    setServers.insert(item);
                }
            }
        }

        return answer;
    }
};


int main() {
    vector<vector<int>> grid;
    int answer;
    Solution solve;

    grid = {{1, 0},
            {1, 1}};
    answer = 3;
    assert(answer == solve.countServers(grid));

    grid = {{1, 0},
            {0, 1}};
    answer = 0;
    assert(answer == solve.countServers(grid));

    grid = {{1, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}};
    answer = 4;
    assert(answer == solve.countServers(grid));


    return 0;
}
