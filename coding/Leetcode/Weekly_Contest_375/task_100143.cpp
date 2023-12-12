// https://leetcode.com/contest/weekly-contest-375/problems/count-tested-devices-after-test-operations/
// Created by omega515 on 10.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int> &batteryPercentages) {
        int answer = 0;
        int n = batteryPercentages.size();
        int val;
        for (int i = 0; i < n; ++i) {
            val = batteryPercentages[i];
            if (val > 0 ){
                ++answer;
                for (int j = i + 1; j < n; ++j) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> batteryPercentages;
    int answer;
    Solution solve;

    batteryPercentages = {1, 1, 2, 1, 3};
    answer = 3;
    assert(answer == solve.countTestedDevices(batteryPercentages));

    batteryPercentages = {0, 1, 2};
    answer = 2;
    assert(answer == solve.countTestedDevices(batteryPercentages));
    return 0;
}

