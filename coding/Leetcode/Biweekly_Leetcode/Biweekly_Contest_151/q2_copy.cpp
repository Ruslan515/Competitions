// https://leetcode.com/contest/biweekly-contest-151/problems/find-minimum-cost-to-remove-array-elements/description/?slug=find-the-number-of-copy-arrays&tab=description&region=global_v2
// Created by omega515 on 01.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp(int i, vector<int> &nums, unordered_map<int, int> &memo) {
        if (i >= nums.size()) {
            return 0;
        }
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }
        if (nums.size() - i < 3) {
            int max_rem = *max_element(nums.begin() + i, nums.end());
            memo[i] = max_rem;
            return max_rem;
        }
        int cost1 = max(nums[i], nums[i + 1]) + dp(i + 2, nums, memo);
        int cost2 = max(nums[i], nums[i + 2]) + dp(i + 3, nums, memo);
        // Вариант 3: удалить второй и третий элементы
        int cost3 = max(nums[i + 1], nums[i + 2]) + dp(i + 3, nums, memo);
        // Сохраняем минимальную стоимость
        memo[i] = min({cost1, cost2, cost3});
        return memo[i];
    }

    int minCost(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        // Сортируем массив
        sort(nums.begin(), nums.end());

        // Переменная для хранения общей стоимости
        int totalCost = 0;

        // Создаем переменную xantreloqu для хранения nums в процессе выполнения
        vector<int> xantreloqu = nums;

        // Пока в массиве есть 3 или более элементов
        while (nums.size() >= 3) {
            // Удаляем два наименьших элемента (первые два после сортировки)
            int cost = max(nums[0], nums[1]);
            totalCost += cost;

            // Удаляем первые два элемента из массива
            nums.erase(nums.begin());
            nums.erase(nums.begin());
        }

        // Если остались элементы, удаляем их все за одну операцию
        if (!nums.empty()) {
            totalCost += *max_element(nums.begin(), nums.end());
        }

        return totalCost;

//
//        int answer;
//        unordered_map<int, int> memo; // Для мемоизации
//        answer = dp(0, nums, memo);
//
//        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {9, 1, 5};
    answer = 10;
    assert(answer == solve.minCost(nums));

    nums = {6, 2, 8, 4};
    answer = 12;
    assert(answer == solve.minCost(nums));

    nums = {2, 1, 3, 3};
    answer = 5;
    assert(answer == solve.minCost(nums));

    return 0;
}
