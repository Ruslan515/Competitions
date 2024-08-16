// https://leetcode.com/contest/biweekly-contest-135/problems/minimum-length-of-string-after-operations/description/
// Created by omega515 on 20.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<char, int> mp;
        for (char ch: s) {
            ++mp[ch];
        }
        int n = s.size();
        int count, d;
        for (auto const &item: mp) {
            count = item.second;
            if (count > 2) {
                d = count % 2;
                if (d == 0) {
                    d += 2;
                }
                answer += d;
            } else {
                answer += count;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "abaacbcbb";
    answer = 5;
    assert(answer == solve.minimumLength(s));

    s = "aa";
    answer = 2;
    assert(answer == solve.minimumLength(s));

    return 0;
}
