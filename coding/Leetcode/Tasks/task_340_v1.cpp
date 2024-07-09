// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 28.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<char, int> mp;
        int n = s.size();
        int left = 0, right = 0;
        char ch;
        while (right < n) {
            ch = s[right];
            if (mp.find(ch) == mp.end()) {  // new char
                if (mp.size() == k) {  // current map size 2 keys
                    answer = max(answer, right - left);
                    char l;
                    while (left < n) {
                        l = s[left];
                        ++left;
                        --mp[l];
                        if (mp[l] == 0) {
                            mp.erase(l);
                            break;
                        }
                    }
                }
                ++mp[ch];

            } else {
                ++mp[ch];
            }

            ++right;
        }
        answer = max(answer, right - left);
        return answer;
    }
};

int main() {
    string s;
    int k;
    int answer;
    Solution solve;

    s = "abee", k = 1;
    answer = 2;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    s = "aa", k = 1;
    answer = 2;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    s = "eceba", k = 2;
    answer = 3;
    assert(answer == solve.lengthOfLongestSubstringKDistinct(s, k));

    return 0;
}
