// https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2023-12-04
// Created by omega515 on 04.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string answer = "";
        int maxEl = -1;
        int n = num.length();
        unordered_map<int, int> mp;
        int val;
        for (int i = 0; i < 3; ++i) {
            val = num[i] - '0';
            mp[val]++;
        }
        if (mp.size() == 1) {
            maxEl = max(maxEl, val);
        }
        for (int i = 3; i < n; ++i) {
            val = num[i - 3] - '0';
            mp[val]--;
            val = num[i] - '0';
            mp[val]++;
            if (mp[val] == 3) {
                maxEl = max(maxEl, val);
            }
        }
        if (maxEl != -1) {
            answer += (maxEl + '0');
            answer += (maxEl + '0');
            answer += (maxEl + '0');
        }

        return answer;
    }
};

int main() {
    string num, answer;
    Solution solve;

    num = "6777133339";
    answer = "777";
    assert(answer == solve.largestGoodInteger(num));

    num = "2300019";
    answer = "000";
    assert(answer == solve.largestGoodInteger(num));

    num = "42352338";
    answer = "";
    assert(answer == solve.largestGoodInteger(num));

    return 0;
}