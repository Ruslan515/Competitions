// https://leetcode.com/problems/lonely-pixel-i/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 12.07.24.
//


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int minCost = y, maxCost = x;
        string minStr = "ba", maxStr = "ab";
        if (x < y) {
            maxCost = y;
            minCost = x;
            maxStr = "ba";
            minStr = "ab";
        }
        stack<char> st1, st2;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            st1.push(s[i]);
        }

        char first, second;
        while (!st1.empty()) {
            first = st1.top();
            st1.pop();
            if (!st1.empty() && first == maxStr[0]) {
                second = st1.top();
                if (second == maxStr[1]) {
                    st1.pop();
                    answer += maxCost;
                    continue;
                }
            } else if (!st2.empty() && first == maxStr[1]) {
                second = st2.top();
                if (second == maxStr[0]) {
                    st2.pop();
                    answer += maxCost;
                    continue;
                }
            }
            st2.push(first);
        }

        while (!st2.empty()) {
            first = st2.top();
            st2.pop();
            if (!st2.empty() && first == minStr[1]) {
                second = st2.top();
                if (second == minStr[0]) {
                    st2.pop();
                    answer += minCost;
                    continue;
                }
            } else if (!st1.empty() && first == minStr[0]) {
                second = st1.top();
                if (second == minStr[1]) {
                    st1.pop();
                    answer += minCost;
                    continue;
                }
            }
            st1.push(first);
        }

        return answer;
    }
};

int main() {
    string s;
    int x, y;
    int answer;
    Solution solve;

    s = "cdbcbbaaabab", x = 4, y = 5;
    answer = 19;
    assert(answer == solve.maximumGain(s, x, y));

    s = "aabbaaxybbaabb", x = 5, y = 4;
    answer = 20;
    assert(answer == solve.maximumGain(s, x, y));

    return 0;
}
