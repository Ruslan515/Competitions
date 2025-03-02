// https://leetcode.com/contest/weekly-contest-346/problems/find-the-punishment-number-of-an-integer/?slug=lexicographically-smallest-palindrome&region=global_v2
// Created by ruslan515 on 21.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isway(string s, int n, int cnt) {
        if (s.empty()) {
            if (cnt == n)
                return 1;
            return 0;
        }
        for (int i = 0; i < s.size(); ++i) {
            string temp = s.substr(0, i + 1);
            int modn = stoi(temp);
            if (modn <= n) {
                if (isway(s.substr(i + 1), n, cnt + modn))
                    return 1;
            }
        }
        return 0;
    }

    int punishmentNumber(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            string temp = to_string(i * i);
            if (isway(temp, i, 0))
                dp[i] = 1;
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (dp[i])
                cnt += i * i;
        }
        return cnt;
    }
};

int main() {
    int n, answer;
    Solution solve;

    n = 10;
    answer = 182;
    assert(solve.punishmentNumber(n) == answer);

    n = 37;
    answer = 1478;
    assert(solve.punishmentNumber(n) == answer);

    return 0;
}
