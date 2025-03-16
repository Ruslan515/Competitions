// https://leetcode.com/contest/weekly-contest-441/problems/closest-equal-element-queries/?slug=count-beautiful-numbers&tab=submissions&tab=1575128947&region=global_v2
// Created by omega515 on 16.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // Шаг 1: Создаем хэш-таблицу для хранения отсортированных индексов каждого значения
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < nums.size(); ++i) {
            valueToIndices[nums[i]].push_back(i);
        }

        // Шаг 2: Обрабатываем запросы
        vector<int> answer;
        for (int query : queries) {
            int value = nums[query];
            const vector<int>& indices = valueToIndices[value];

            // Если нет других индексов с таким значением, возвращаем -1
            if (indices.size() <= 1) {
                answer.push_back(-1);
                continue;
            }

            // Используем бинарный поиск для нахождения ближайшего индекса
            auto it = lower_bound(indices.begin(), indices.end(), query);
            int minDistance = INT_MAX;

            // Проверяем предыдущий элемент
            if (it != indices.begin()) {
                int prevIndex = *(it - 1);
                int distance = min(abs(query - prevIndex), (int)nums.size() - abs(query - prevIndex));
                minDistance = min(minDistance, distance);
            } else {
                // Если query меньше всех индексов, проверяем последний индекс (циклический случай)
                int prevIndex = indices.back();
                int distance = min(abs(query - prevIndex), (int)nums.size() - abs(query - prevIndex));
                minDistance = min(minDistance, distance);
            }

            // Проверяем следующий элемент
            if (it != indices.end() && *it != query) {
                int nextIndex = *it;
                int distance = min(abs(query - nextIndex), (int)nums.size() - abs(query - nextIndex));
                minDistance = min(minDistance, distance);
            } else if (it == indices.end()) {
                // Если query больше всех индексов, проверяем первый индекс (циклический случай)
                int nextIndex = indices.front();
                int distance = min(abs(query - nextIndex), (int)nums.size() - abs(query - nextIndex));
                minDistance = min(minDistance, distance);
            }

            // Если minDistance не обновлен, значит, подходящий индекс не найден
            answer.push_back(minDistance == INT_MAX ? -1 : minDistance);
        }

        return answer;
    }
};



int main() {
    vector<int> nums, queries;
    vector<int> answer;
    Solution solve;

    nums = {1, 2, 3, 4}, queries = {0, 1, 2, 3};
    answer = {-1, -1, -1, -1};
    assert(answer == solve.solveQueries(nums, queries));

    nums = {1, 3, 1, 4, 1, 3, 2}, queries = {0, 3, 5};
    answer = {2, -1, 3};
    assert(answer == solve.solveQueries(nums, queries));

    return 0;
}
