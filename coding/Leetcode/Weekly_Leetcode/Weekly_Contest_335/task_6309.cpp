// https://leetcode.com/contest/weekly-contest-335/problems/split-the-array-to-make-coprime-products/
// Created by ruslan515 on 05.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gcd (long long a, long long b) {
        while (b) {
            a %= b;
            swap (a, b);
        }
        return a;
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        long long product = 1;
        for (int x: nums) {
            product *= x;
        }
        long long prefix = nums[0];
        long long suffix = product / prefix;

        int i = 0;
        int answer = -1;
        for (; i <= n - 2;) {
            if (gcd(prefix, suffix) == 1) {
                answer = i;
                break;
            }
            ++i;
            int t = nums[i];
            prefix *= t;
            suffix /= t;
        }
        return answer;
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

    cout << solve.findValidSplit(nums);

    return 0;
}