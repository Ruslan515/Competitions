// https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
// Created by omega515 on 11.01.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        int n = s.size();
        if (n < k) {
            return answer;
        }

        unordered_map<char, int> mp;

        for (char ch: s) {
            ++mp[ch];
        }
        int cnt = 0;
        for (auto const &[key, val]: mp) {
            if (val % 2 != 0) {
                ++cnt;
            }
        }
        if (cnt > k) {
            return answer;
        }
        answer = true;

        return answer;
    }
};


int main() {
    string s;
    int k;
    bool answer;
    Solution solve;

    s = "annabelle", k = 2;
    answer = true;
    assert(answer == solve.canConstruct(s, k));

    s = "leetcode", k = 3;
    answer = false;
    assert(answer == solve.canConstruct(s, k));


    s = "true", k = 4;
    answer = true;
    assert(answer == solve.canConstruct(s, k));

    return 0;
}
