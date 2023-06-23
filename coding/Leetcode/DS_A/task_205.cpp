// https://leetcode.com/problems/isomorphic-strings/
// Created by ruslan515 on 22.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIso(string s, string t) {
        unordered_map<char, char> mp;
        bool answer = true;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char ch1 = s[i];
            char ch2 = t[i];
            if (mp.find(ch2) != mp.end()) {
                char val = mp[ch2];
                if (val != ch1) {
                    answer = false;
                    break;
                }
            } else {
                mp[ch2] = ch1;
            }
        }
        return answer;
    }
    bool isIsomorphic(string s, string t) {
        bool answer = isIso(s, t) && isIso(t, s);
        return answer;
    }
};

int main() {
    bool answer;
    string s, t;
    Solution solve;

    s = "badc", t = "baba";
    answer = false;
    assert(answer == solve.isIsomorphic(s, t));

    s = "egg", t = "add";
    answer = true;
    assert(answer == solve.isIsomorphic(s, t));

    s = "foo", t = "bar";
    answer = false;
    assert(answer == solve.isIsomorphic(s, t));

    s = "paper", t = "title";
    answer = true;
    assert(answer == solve.isIsomorphic(s, t));

    return 0;
}