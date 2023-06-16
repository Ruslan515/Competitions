// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Created by ruslan515 on 16.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        int n = s.size();
        int left = 0, right = 0;
        set<char> st;
        while (right < n) {
            while (right < n && st.find(s[right]) == st.end() ) {
                st.insert(s[right]);
                ++right;
            }

            int temp = right - left;
            answer = max(answer, temp);

            while (left < n && s[left] != s[right]) {
                st.erase(s[left]);
                ++left;
            }
            st.erase(s[left]);
            ++left;
        }

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "abcabcbb";
    answer = 3;
    assert(answer == solve.lengthOfLongestSubstring(s));

    s = "bbbbb";
    answer = 1;
    assert(answer == solve.lengthOfLongestSubstring(s));

    s = "pwwkew";
    answer = 3;
    assert(answer == solve.lengthOfLongestSubstring(s));

    return 0;
}