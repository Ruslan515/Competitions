// https://leetcode.com/contest/biweekly-contest-98/problems/minimum-impossible-or/
// Created by ruslan515 on 18.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        map<int, int> mp;
        for(auto x: nums) {
            mp[x]++;
        }
        int ans = 1;
        while (true) {
            if (mp.find(ans) == mp.end()) {
                return ans;
            }
            ans *= 2;
        }

        return ans;
    }
};

void read_data(vector<int>& nums) {
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;
    cout <<  solve.minImpossibleOR(nums);

    return 0;
}