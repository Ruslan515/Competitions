// https://leetcode.com/contest/biweekly-contest-99/problems/count-ways-to-group-overlapping-ranges/
// Created by ruslan515 on 04.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        vector<vector<int>> v;
        int n = ranges.size();
        v.push_back(ranges[0]);
        int x1, x2;
        for (int i = 1; i < n; ++i) {
            x1 = ranges[i][0];
            x2 = ranges[i][1];
            for (int j = 0; j < v.size(); ++j) {

            }

        }
    }
};


void read_data(vector<vector<int>> &ranges) {
    int n;
    cin >> n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        ranges.push_back({a, b});
    }
    return;
}

int main() {
    vector<vector<int>> ranges;
    read_data(ranges);
    Solution solve;
    cout << solve.countWays(ranges);

    return 0;
}