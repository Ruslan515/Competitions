// https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
// Created by omega515 on 01.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string> &details) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        string ageStr;
        int age;
        for (string info: details) {
            ageStr = info.substr(11, 2);
            age = stoi(ageStr);
            if (age > 60) {
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
    assert(answer == solve.countSeniors(details));

    details = {"1313579440F2036", "2921522980M5644"};
    answer = 0;
    assert(answer == solve.countSeniors(details));

    return 0;
}
