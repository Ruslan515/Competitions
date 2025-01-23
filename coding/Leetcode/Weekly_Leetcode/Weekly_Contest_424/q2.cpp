// https://leetcode.com/contest/weekly-contest-424/problems/make-array-elements-equal-to-zero/
// Created by omega515 on 17.11.24.
//

#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
//        cout.tie(NULL);
//
//        bool answer = false;
//        int n = nums.size();
//        int m = queries.size();
//        for (int i = 0; i < m; ++i) {
//            vector<int> index = queries[i];
//            int left = index[0];
//            int right = index[1];
//            for (int j = left; j <= right; ++j) {
//                if (nums[j] != 0) {
//                    --nums[j];
//                }
//            }
//        }
//
//        int sums = 0;
//        for (int i = 0; i < n; ++i) {
//            sums += nums[i];
//        }
//        if (sums == 0) {
//            answer = true;
//        }
//
//        return answer;
//    }
//};

class Solution {
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        // Массив для подсчета разностей
        vector<long long> diff(n + 1, 0);

        // Обрабатываем запросы с помощью техники разности префиксных сумм
        for (const auto &query: queries) {
            int left = query[0];
            int right = query[1];
            diff[left]++;
            diff[right + 1]--;
        }

        // Вычисляем накопительную сумму и сравниваем с исходным массивом
        long long curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            if (curr < nums[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<int> nums;
    vector<vector<int>> queries;
    bool answer;
    Solution solve;

    nums = {4, 3, 2, 1}, queries = {{1, 3},
                                    {0, 2}};
    answer = false;
    assert(answer == solve.isZeroArray(nums, queries));

    nums = {1, 0, 1}, queries = {{0, 2}};
    answer = true;
    assert(answer == solve.isZeroArray(nums, queries));

    return 0;
}
