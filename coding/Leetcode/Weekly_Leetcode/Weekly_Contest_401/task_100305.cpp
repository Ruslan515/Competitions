// https://leetcode.com/contest/weekly-contest-401/problems/find-the-n-th-value-after-k-seconds/
// Created by omega515 on 09.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int answer = 0;
        const int MOD = 1e9 + 7;
        vector<long long> a(n, 1);

        for (int sec = 1; sec <= k; sec++) {
            vector<long long> temp(n);
            long long sum = 0;

            for (int i = 0; i < n; i++) {
                sum = (sum + a[i]) % MOD;
                temp[i] = sum;
            }

            a = temp;
        }

        return a[n - 1];
    }
};

int main() {
    int n, k;
    int answer;
    Solution solve;

    n = 4, k = 5;
    answer = 56;
    assert(answer == solve.valueAfterKSeconds(n, k));

    n = 5, k = 3;
    answer = 35;
    assert(answer == solve.valueAfterKSeconds(n, k));

    return 0;
}
