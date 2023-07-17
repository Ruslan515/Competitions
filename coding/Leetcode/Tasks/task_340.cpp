// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Created by Ruslan Khalikov on 13.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        int n = s.size();
        int answer = 0;
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        char temp;
        while (right < n) {
            while (right < n && mp.size() <= k) {
                temp = s[right];
                ++mp[temp];
                if (mp.size() <= k) {
                    ++right;
                } else {
                    break;
                }
            }
            answer = max(answer, right - left);
            while (left < n && mp.size() > k) {
                temp = s[left];
                --mp[temp];
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
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
    int k, answer;
    Solution solve;

    s = "aba", k = 1;
    answer = 1;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    s = "a", k = 0;
    answer = 0;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    s = "eceba", k = 2;
    answer = 3;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    s = "aa", k = 1;
    answer = 2;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    return 0;
}