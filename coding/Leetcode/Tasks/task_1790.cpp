// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05
// Created by omega515 on 05.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        unordered_map<char, int> mp1, mp2;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            ++mp1[s1[i]];
            ++mp2[s2[i]];
        }
        if (mp1 != mp2) {
            return answer;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++cnt;
                if (cnt > 2) {
                    return answer;
                }

            }
        }

        answer = true;
        return answer;
    }
};


int main() {
    string s1, s2;
    bool answer;
    Solution solve;

    s1 = "syvse", s2 = "yvsse";
    answer = false;
    assert(answer == solve.areAlmostEqual(s1, s2));

    s1 = "bank", s2 = "kanb";
    answer = true;
    assert(answer == solve.areAlmostEqual(s1, s2));

    s1 = "attack", s2 = "defend";
    answer = false;
    assert(answer == solve.areAlmostEqual(s1, s2));

    s1 = "kelb", s2 = "kelb";
    answer = true;
    assert(answer == solve.areAlmostEqual(s1, s2));


    return 0;
}

