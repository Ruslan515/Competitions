// https://leetcode.com/problems/permutation-in-string/
// Created by ruslan515 on 22.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool answer = false;
        int n1 = s1.size();
        int n2 = s2.size();
        if (n2 < n1) {
            return answer;
        }
        unordered_map<char, int> mp1;
        for (char ch: s1) {
            ++mp1[ch];
        }

        unordered_map<char, int> mp2;
        for (int i = 0; i < n1; ++i) {
            ++mp2[s2[i]];
        }
        if (mp1 == mp2) {
            answer = true;
        } else {
            for (int start = n1; start < n2; ++start) {
                char first = s2[start - n1];
                char last = s2[start];
                --mp2[first];
                if (mp2[first] == 0) {
                    mp2.erase(first);
                }
                ++mp2[last];
                if (mp1 == mp2) {
                    answer = true;
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    bool answer;
    string s1, s2;
    Solution solve;

    s1 = "adc", s2 = "dcda";
    answer = true;
    assert(answer == solve.checkInclusion(s1, s2));

    s1 = "ab", s2 = "eidbaooo";
    answer = true;
    assert(answer == solve.checkInclusion(s1, s2));

    s1 = "ab", s2 = "eidboaoo";
    answer = false;
    assert(answer == solve.checkInclusion(s1, s2));

    return 0;
}