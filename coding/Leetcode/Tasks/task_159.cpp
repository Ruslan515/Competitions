// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
// Created by omega515 on 25.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int answer = 0;
        unordered_map<char, int> mp;
        int n = s.size();
        int left = 0, right = 0;
        char ch;
        while (right < n) {
            while (right < n && mp.size() < 3) {
                ch = s[right];
                ++mp[ch];
                if (mp.size() < 3) {
                    ++right;
                } else {
                    break;
                }

            }
            answer = max(answer, right - left);
            while (left < n && mp.size() > 2) {
                ch = s[left];
                --mp[ch];
                if (mp[ch] == 0) {
                    mp.erase(ch);
                }
                ++left;
            }
            ++right;
        }

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "abcabcabc";
    answer = 2;
    assert(answer == solve.lengthOfLongestSubstringTwoDistinct(s));

    s = "eceba";
    answer = 3;
    assert(answer == solve.lengthOfLongestSubstringTwoDistinct(s));

    s = "abc";
    answer = 2;
    assert(answer == solve.lengthOfLongestSubstringTwoDistinct(s));

    s = "ccaabbb";
    answer = 5;
    assert(answer == solve.lengthOfLongestSubstringTwoDistinct(s));

    return 0;
}