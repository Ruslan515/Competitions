// https://leetcode.com/contest/biweekly-contest-104/problems/number-of-senior-citizens/
// Created by Ruslan Khalikov on 13.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string> &details) {
        int answer = 0;
        for (auto s: details) {
            string sAge = s.substr(11, 2);
            int iAge = stoi(sAge);
            if (iAge > 60) {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
    vector<string> details;
    int answer;
    Solution solve;

    details = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};
    answer = 2;
    assert(solve.countSeniors(details) == answer);

    details = {"1313579440F2036", "2921522980M5644"};
    answer = 0;
    assert(solve.countSeniors(details) == answer);

    return 0;
}
