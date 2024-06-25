// https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
// Created by omega515 on 10.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        int answer = 0;
        vector<int> copy(heights);
        sort(copy.begin(), copy.end());
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            if (copy[i] != heights[i]) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> heights;
    int answer;
    Solution solve;

    heights = {1, 1, 4, 2, 1, 3};
    answer = 3;
    assert(answer == solve.heightChecker(heights));

    heights = {5, 1, 2, 3, 4};
    answer = 5;
    assert(answer == solve.heightChecker(heights));

    heights = {1, 2, 3, 4, 5};
    answer = 0;
    assert(answer == solve.heightChecker(heights));

    return 0;
}
