//
// Created by omega515 on 01.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countArrays(vector<int> &original, vector<vector<int>> &bounds) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        int n = original.size();

        // Начальные значения для диапазона k
        long long minK = LLONG_MIN;
        long long maxK = LLONG_MAX;

        // Находим пересечение всех ограничений
        for (int i = 0; i < n; i++) {
            // Ограничение: ui <= original[i] + k <= vi
            // Преобразуем в: ui - original[i] <= k <= vi - original[i]
            long long lowerBound = (long long) bounds[i][0] - original[i];
            long long upperBound = (long long) bounds[i][1] - original[i];

            // Обновляем общий диапазон
            minK = max(minK, lowerBound);
            maxK = min(maxK, upperBound);

            // Если диапазон пуст, возвращаем 0
            if (minK > maxK) {
                return 0;
            }
        }

        // Если maxK или minK выходят за пределы int, нужно быть осторожным
        if (minK == LLONG_MIN || maxK == LLONG_MAX) {
            return 0; // Такой случай невозможен в данной задаче
        }

        // Количество целых чисел в диапазоне [minK, maxK]
        return (int) (maxK - minK + 1);
    }
};

int main() {
    vector<int> original;
    vector<vector<int>> bounds;
    int answer;
    Solution solve;

    original = {1, 2, 3, 4}, bounds = {{1, 2},
                                       {2, 3},
                                       {3, 4},
                                       {4, 5}};
    answer = 2;
    assert(answer == solve.countArrays(original, bounds));

    original = {1, 2, 3, 4}, bounds = {{1, 10},
                                       {2, 9},
                                       {3, 8},
                                       {4, 7}};
    answer = 4;
    assert(answer == solve.countArrays(original, bounds));

    original = {1, 2, 1, 2}, bounds = {{1, 1},
                                       {2, 3},
                                       {3, 3},
                                       {2, 3}};
    answer = 0;
    assert(answer == solve.countArrays(original, bounds));


    return 0;
}
