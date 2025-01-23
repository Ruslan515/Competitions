// https://leetcode.com/contest/weekly-contest-328/problems/count-the-number-of-good-subarrays/
// Created by ruslan515 on 15.01.23.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long i = 0, ans = 0, count = 0, n = nums.size();
        unordered_map<long long, long long> m;

        for(int j=0; j<n; j++) {
            m[nums[j]]++;
            if(m[nums[j]] > 1) count += m[nums[j]]  - 1;

            while(i <= j && count >= k) {
                ans += n - j;
                m[nums[i]]--;
                if(m[nums[i]] >= 1) count -= m[nums[i]];
                i++;
            }
        }
        return ans;
    }
};

void read_data(vector<int>& nums, int & k) {
    cin >> k;
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    int k;
    read_data(nums, k);
    Solution solve;
    cout << solve.countGood(nums, k));
    return 0;
}