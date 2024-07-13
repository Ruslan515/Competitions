// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 09.07.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = s.size();
        if (k > n) {
            return answer;
        }

        unordered_map<char, int> mp;
        string tmp = "";

        for (int i = 0; i < k; ++i) {
            tmp += s[i];
            ++mp[s[i]];
        }
        if (mp.size() == k) {
            ++answer;
        }
        int last;
        char ch;
        for (int i = 0; i < n - k; ++i) {
            ch = s[i];
            tmp.erase(0, 1);
            --mp[ch];
            if (mp[ch] == 0) {
                mp.erase(ch);
            }
            last = i + k;
            ch = s[last];
            tmp += ch;
            ++mp[ch];
            if (mp.size() == k) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    int k;
    int answer;
    Solution solve;

    s = "havefunonleetcode", k = 5;
    answer = 6;
    assert(answer == solve.numKLenSubstrNoRepeats(s, k));

    s = "home", k = 5;
    answer = 0;
    assert(answer == solve.numKLenSubstrNoRepeats(s, k));

    return 0;
}
