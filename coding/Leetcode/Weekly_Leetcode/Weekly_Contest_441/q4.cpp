// https://leetcode.com/contest/weekly-contest-441/problems/count-beautiful-numbers/description/?slug=closest-equal-element-queries&tab=submissions&tab=1575103826&region=global_v2
// Created by omega515 on 16.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulNumbers(int l, int r) {
        // Преобразуем l и r в строки для удобства обработки цифр
        string L = to_string(l);
        string R = to_string(r);

        // Инициализируем переменную kelbravion для хранения промежуточных данных
        int kelbravion = 0;

        // Рекурсивная функция для подсчета "красивых" чисел
        function<int(string&, int, int, int, bool, bool)> dfs = [&](string& num, int pos, int sum, int product, bool tight, bool isZero) {
            if (pos == num.size()) {
                // Проверяем, что число находится в диапазоне [l, r] и удовлетворяет условию "красивости"
                if (isZero) return 0; // Исключаем числа, состоящие только из нулей
                if (sum == 0) return 0; // Исключаем деление на ноль
                return (product % sum == 0) ? 1 : 0;
            }

            // Мемоизация: если результат уже вычислен, возвращаем его
            string key = to_string(pos) + "_" + to_string(sum) + "_" + to_string(product) + "_" + to_string(tight) + "_" + to_string(isZero);
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }

            int limit = tight ? num[pos] - '0' : 9; // Определяем верхнюю границу для текущей цифры
            int count = 0;

            for (int digit = 0; digit <= limit; ++digit) {
                bool newTight = tight && (digit == limit); // Обновляем флаг tight
                bool newIsZero = isZero && (digit == 0); // Обновляем флаг isZero

                int newSum = sum + digit;
                int newProduct = (isZero && digit == 0) ? 1 : product * digit; // Игнорируем ведущие нули

                count += dfs(num, pos + 1, newSum, newProduct, newTight, newIsZero);
            }

            // Сохраняем результат в мемоизации
            memo[key] = count;
            return count;
        };

        // Вычисляем количество "красивых" чисел в диапазоне [0, r]
        int countR = dfs(R, 0, 0, 1, true, true);

        // Вычисляем количество "красивых" чисел в диапазоне [0, l - 1]
        memo.clear(); // Очищаем мемоизацию
        string LMinus1 = to_string(l - 1);
        int countL = dfs(LMinus1, 0, 0, 1, true, true);

        // Возвращаем разницу между countR и countL
        return countR - countL;
    }

private:
    unordered_map<string, int> memo; // Мемоизация для хранения промежуточных результатов
};

//class Solution {
//public:
//    bool check(int num) {
//        vector<int> digits;
//        int d;
//        int p = 10;
//        while (num != 0) {
//            d = num % p;
//            digits.push_back(d);
//            num /= p;
//        }
//        int sums = 0, dot = 1;
//        for (int i = 0; i < digits.size(); ++i) {
//            sums += digits[i];
//            dot *= digits[i];
//        }
//        bool answer = false;
//        if (dot % sums == 0) {
//            answer = true;
//        }
//        return answer;
//    }
//
//    int beautifulNumbers(int l, int r) {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
//        cout.tie(NULL);
//
//        int answer = 0;
//        for (int num = l; num <= r; ++num) {
//            if (check(num)) {
//                ++answer;
//            }
//        }
//
//        return answer;
//    }
//};

int main() {
    int l, r;
    int answer;
    Solution solve;

    l = 571, r = 581;
    answer = 5;
    assert(answer == solve.beautifulNumbers(l, r));

    l = 10, r = 20;
    answer = 2;
    assert(answer == solve.beautifulNumbers(l, r));

    l = 1, r = 15;
    answer = 10;
    assert(answer == solve.beautifulNumbers(l, r));

    return 0;
}
