// https://leetcode.com/problems/alternating-groups-i/description/
// Created by omega515 on 09.03.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &colors) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = colors.size();
        int left, curr, right;
        for (int i = 0; i < n; ++i) {
            left = colors[i];
            curr = colors[(i + 1) % n];
            right = colors[(i + 2) % n];
            if (left != curr && left == right) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> colors;
    int answer;
    Solution solve;

    colors = {0, 1, 0, 0, 1};
    answer = 3;
    assert(answer == solve.numberOfAlternatingGroups(colors));

    colors = {1, 1, 1};
    answer = 0;
    assert(answer == solve.numberOfAlternatingGroups(colors));

    return 0;
}

