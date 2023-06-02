// https://leetcode.com/problems/get-equal-substrings-within-budget/
// Created by ruslan515 on 31.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int answer = 0;

        int n = s.size();
        vector<int> diffCost(n, 0);
        for (int i = 0; i < n; ++i) {
            int diff = abs((s[i] - 'a') - (t[i] - 'a'));
            diffCost[i] = diff;
        }

        int left = 0, right = 0;
        int tempSum = 0;
        for (; right < n; ++right) {
            tempSum += diffCost[right];
            while (tempSum > maxCost) {
                tempSum -= diffCost[left];
                ++left;
            }
            int tempLen = right - left + 1;
            answer = max(answer, tempLen);
        }

        return answer;
    }
};

int main() {
    string s, t;
    int maxCost, answer;
    Solution solve;

    s = "abcd", t = "bcdf", maxCost = 3;
    answer = 3;
    assert(solve.equalSubstring(s, t, maxCost) == answer);

    s = "abcd", t = "cdef", maxCost = 3;
    answer = 1;
    assert(solve.equalSubstring(s, t, maxCost) == answer);

    s = "abcd", t = "acde", maxCost = 0;
    answer = 1;
    assert(solve.equalSubstring(s, t, maxCost) == answer);

    return 0;
}
