// https://leetcode.com/contest/biweekly-contest-150/problems/sum-of-good-numbers/description/?slug=separate-squares-i&tab=description&region=global_v2
// Created by omega515 on 15.02.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double calculateAreaBelow(const vector<vector<int>> &squares, double y) {
        double area = 0.0;
        for (const auto &square: squares) {
            int x = square[0], yi = square[1], l = square[2];
            if (yi + l <= y) {
                // Полностью ниже линии
                area += static_cast<double>(l) * l; // Приводим к double
            } else if (yi < y) {
                // Частично ниже линии
                double heightBelow = y - yi;
                area += heightBelow * l; // Площадь под линией
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>> &squares) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        double low = 0.0, high = 0.0;

        // Находим максимальное значение y для верхней границы
        for (const auto &square: squares) {
            high = max(high, static_cast<double>(square[1] + square[2]));
        }

        // Вычисляем общую площадь всех квадратов
        double totalArea = 0.0;
        for (const auto &square: squares) {
            totalArea += static_cast<double>(square[2]) * square[2]; // Приводим к double
        }

        // Бинарный поиск
        const double precision = 1e-5;
        while (high - low > precision) {
            double mid = low + (high - low) / 2.0;
            double areaBelow = calculateAreaBelow(squares, mid);

            if (areaBelow * 2 < totalArea) {
                low = mid; // Нужно поднять линию
            } else {
                high = mid; // Нужно опустить линию
            }
        }

        return low; // или high, так как они близки друг к другу
    }
};

int main() {
    vector<vector<int>> squares;
    double answer;
    Solution solve;

    squares = {{522261215, 954313664, 461744743},
               {628661372, 718610752, 21844764},
               {619734768, 941310679, 91724451},
               {352367502, 656774918, 591943726},
               {860247066, 905800565, 853111524},
               {817098516, 868361139, 817623995},
               {580894327, 654069233, 691552059},
               {182377086, 256660052, 911357},
               {151104008, 908768329, 890809906},
               {983970552, 992192635, 462847045}};
    answer = 1.00000;
    assert(abs(answer - solve.separateSquares(squares)) < 1e-5);

    squares = {{0, 0, 1},
               {2, 2, 1}};
    answer = 1.00000;
    assert(abs(answer - solve.separateSquares(squares)) < 1e-5);
//    assert(answer == solve.separateSquares(squares));

    squares = {{0, 0, 2},
               {1, 1, 1}};
    answer = 1.16667;
    assert(abs(answer - solve.separateSquares(squares)) < 1e-5);
//    assert(answer == solve.separateSquares(squares));

    return 0;
}
