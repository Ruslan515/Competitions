// https://leetcode.com/contest/weekly-contest-439/problems/sum-of-k-subarrays-with-length-at-least-m/?slug=lexicographically-smallest-generated-string&region=global_v2
// Created by omega515 on 02.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int> &nums, int k, int m) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        // Проверка на возможность выбора k подмассивов длины не менее m
        if (k * m > n) {
            return INT_MIN;
        }

        // Префиксные суммы для быстрого вычисления суммы подмассива
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // dp[i][j] = максимальная сумма j подмассивов, заканчивающихся на позиции i
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1e18));

        // Базовый случай: сумма 0 подмассивов равна 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Динамическое программирование
        for (int j = 1; j <= k; j++) {
            // Для каждого количества подмассивов j
            long long maxPrev = -1e18;  // Максимальное значение dp[s][j-1] - prefixSum[s]

            for (int i = m; i <= n; i++) {
                // Обновляем максимальное значение для предыдущей позиции
                if (i - m >= 0) {
                    maxPrev = max(maxPrev, dp[i - m][j - 1] - prefixSum[i - m]);
                }

                // Используем сохраненное максимальное значение
                dp[i][j] = max(dp[i - 1][j], maxPrev + prefixSum[i]);
            }
        }

        return dp[n][k];
    }
};


int main() {
    vector<int> nums;
    int k, m;
    int answer;
    Solution solve;

    nums = {1, 2, -1, 3, 3, 4}, k = 2, m = 2;
    answer = 13;
    assert(answer == solve.maxSum(nums, k, m));

    nums = {-10, 3, -1, -2}, k = 4, m = 1;
    answer = -10;
    assert(answer == solve.maxSum(nums, k, m));

    return 0;
}
