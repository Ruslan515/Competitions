// https://leetcode.com/contest/weekly-contest-333/problems/minimum-operations-to-reduce-an-integer-to-0/
// Created by ruslan515 on 19.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        if (n == 1) {
            ans = 1;
        } else if (n % 2 == 0) {
            if (!(n & (n - 1))) {
                ans = 1;
            } else {
                int n_sum = n + 2;
                int n_diff = n - 2;
                bool a_sum = !(n_sum & (n_sum - 1));
                bool a_diff = !(n_diff & (n_diff - 1));;
                if (a_sum || a_diff) {
                    ans = 2;
                } else {
                    ans = 3;
                }
            }
        } else {
            int n_sum = n + 1;
            int n_diff = n - 1;
            bool a_sum = !(n_sum & (n_sum - 1));
            bool a_diff = !(n_diff & (n_diff - 1));;
            if (a_sum || a_diff) {
                ans = 2;
            } else {
                ans = 3;
            }
        }

        return ans;
    }
};


void read_data(int &n) {
    cin >> n;
    return;
}

int main() {
    int n;
    read_data(n);
    Solution solve;
    cout << solve.minOperations(n);

    return 0;
}