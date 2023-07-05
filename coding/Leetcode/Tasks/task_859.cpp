// https://leetcode.com/problems/buddy-strings/
// Created by ruslan515 on 03.07.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        bool answer = false;
        int n1 = s.size();
        int n2 = goal.size();
        if (n1 != n2) {
            return answer;
        }
        map<char, int> mp1, mp2;
        for (int i = 0; i < n1; ++i) {
            ++mp1[s[i]];
            ++mp2[goal[i]];
        }
        if (mp1 != mp2) {
            return answer;
        }

        int count = 0;
        for (int i = 0; i < n1; ++i) {
            if (s[i] != goal[i]) {
                ++count;
            }
        }
        if (count == 0) {
            for (auto el: mp1) {
                char key = el.first;
                int val = el.second;
                if (val >= 2) {
                    return true;
                }
            }
            return answer;
        } else if (count > 2) {
            return answer;
        }
        answer = true;

        return answer;
    }
};

int main() {
    string s, goal;
    bool answer;
    Solution solve;

    s = "abab", goal = "baba";
    answer = false;
    assert(answer == solve.buddyStrings(s, goal));

    s = "aa", goal = "aa";
    answer = true;
    assert(answer == solve.buddyStrings(s, goal));

    s = "ab", goal = "ba";
    answer = true;
    assert(answer == solve.buddyStrings(s, goal));

    s = "ab", goal = "ab";
    answer = false;
    assert(answer == solve.buddyStrings(s, goal));

    return 0;
}
