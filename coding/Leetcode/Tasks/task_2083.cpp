// https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/?envType=weekly-question&envId=2024-06-08
// Created by omega515 on 10.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long answer = 0;
        unordered_map<char, long long > mp;
        for (char ch: s) {
            ++mp[ch];
        }
        unordered_map<char, long long >::iterator it = mp.begin();

        for (; it != mp.end(); ++it) {
            long long  val = it->second;
            answer += (long long) (val * (val + 1) / 2);
        }

        return answer;
    }
};

int main() {
    string s;
    long long answer;
    Solution solve;

    s = "abcba";
    answer = 7;
    assert(answer == solve.numberOfSubstrings(s));

    s = "abacad";
    answer = 9;
    assert(answer == solve.numberOfSubstrings(s));

    s = "a";
    answer = 1;
    assert(answer == solve.numberOfSubstrings(s));

    return 0;
}
