// https://leetcode.com/contest/biweekly-contest-151/problems/find-minimum-cost-to-remove-array-elements/description/?slug=find-the-number-of-copy-arrays&tab=description&region=global_v2
// Created by omega515 on 01.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &nums) {
        // Сортируем входной массив для оптимизации мемоизации
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // Проверяем, что все элементы уникальны
        bool allUnique = true;
        for (int i = 1; i < sortedNums.size(); i++) {
            if (sortedNums[i] == sortedNums[i - 1]) {
                allUnique = false;
                break;
            }
        }

        // Если все элементы уникальны, можем использовать битовую маску
        if (allUnique) {
            return solveWithBitmask(nums);
        } else {
            // Иначе используем мемоизацию с вектором
            memo.clear();
            return solve(nums);
        }
    }

private:
    // Мемоизация для уже решенных подзадач
    unordered_map<string, int> memo;

    // Функция для преобразования вектора в строку (для использования в качестве ключа)
    string vectorToString(const vector<int> &v) {
        string result;
        for (int num: v) {
            result += to_string(num) + ",";
        }
        return result;
    }

    int solve(vector<int> &nums) {
        int n = nums.size();

        // Базовые случаи
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Проверяем, решали ли мы уже эту подзадачу
        string key = vectorToString(nums);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int result = INT_MAX;

        // Перебираем все возможные пары элементов для удаления
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Стоимость удаления пары
                int cost = max(nums[i], nums[j]);

                // Создаем новый массив без элементов i и j
                vector<int> remaining;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        remaining.push_back(nums[k]);
                    }
                }

                // Рекурсивно решаем для оставшихся элементов
                int remainingCost = solve(remaining);

                // Обновляем результат
                result = min(result, cost + remainingCost);
            }
        }

        // Сохраняем результат в мемоизации
        memo[key] = result;
        return result;
    }

    // Решение с использованием битовой маски для оптимизации
    int solveWithBitmask(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(1 << n, INT_MAX);

        // Базовый случай: пустое множество
        dp[0] = 0;

        // Базовый случай: один элемент
        for (int i = 0; i < n; i++) {
            dp[1 << i] = nums[i];
        }

        // Заполняем dp для всех возможных подмножеств

        for (int mask = 1; mask < (1 << n); mask++) {
            int count = __builtin_popcount(mask);

            // Если нечетное количество элементов, нужно удалить один элемент отдельно
            if (count % 2 == 1) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        dp[mask] = min(dp[mask], nums[i] + dp[mask ^ (1 << i)]);
                    }
                }
            }
                // Если четное количество элементов, удаляем пары
            else if (count >= 2) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        for (int j = i + 1; j < n; j++) {
                            if (mask & (1 << j)) {
                                int newMask = mask ^ (1 << i) ^ (1 << j);
                                dp[mask] = min(dp[mask], max(nums[i], nums[j]) + dp[newMask]);
                            }
                        }
                    }
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {1, 20, 7, 8, 18};
    answer = 35;
    assert(answer == solve.minCost(nums));

    nums = {12, 15, 1, 15, 18};
    answer = 34;
    assert(answer == solve.minCost(nums));

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
