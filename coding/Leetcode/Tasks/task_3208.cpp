// https://leetcode.com/problems/alternating-groups-ii/description/
// Created by omega515 on 09.03.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool check(vector<int> &colors, int k, int start) {
        bool answer = true;
        int n = colors.size();
        for (int i = start; i < start + k - 1; ++i) {
            if (colors[i % n] == colors[(i + 1) % n]) {
                answer = false;
                break;
            }
        }
        return answer;
    }

    int numberOfAlternatingGroups(vector<int> &colors, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        


        return answer;
    }
};

int main() {
    vector<int> colors;
    int k;
    int answer;
    Solution solve;

    colors = {0, 1, 0, 1, 0}, k = 3;
    answer = 3;
    assert(answer == solve.numberOfAlternatingGroups(colors, k));

    colors = {0, 1, 0, 0, 1, 0, 1}, k = 6;
    answer = 2;
    assert(answer == solve.numberOfAlternatingGroups(colors, k));

    colors = {1, 1, 0, 1}, k = 4;
    answer = 0;
    assert(answer == solve.numberOfAlternatingGroups(colors, k));

    return 0;
}

