// https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18
// Created by omega515 on 18.04.2025.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rle(string &s) {
        vector<vector<int>> freq;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int left = i, rigth = i + 1;
            while (rigth < n && s[left] == s[rigth]) {
                ++rigth;
            }
            int cnt = rigth - left;
            freq.push_back({s[i] - '0', cnt});
            i = rigth;
        }
        s = "";
        for (i = 0; i < freq.size(); ++i) {
            s += to_string(freq[i][1]) + to_string(freq[i][0]);
        }
    }

    string countAndSay(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "1";
        if (n == 1) {
            return answer;
        }
        for (int i = 1; i < n; ++i) {
            rle(answer);
        }

        return answer;
    }
};

int main() {
    int n;
    string answer;
    Solution solve;

    n = 4;
    answer = "1211";
    assert(answer == solve.countAndSay(n));

    n = 1;
    answer = "1";
    assert(answer == solve.countAndSay(n));

    return 0;
}
