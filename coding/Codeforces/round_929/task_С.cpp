// https://codeforces.com/contest/1933/problem/C
// Created by ruslan515 on 27.02.2024
//

#include<bits/stdc++.h>

using namespace std;

// Функция для подсчета делителей числа
int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) // Если делители равны, учитываем их как один
                cnt++;
            else // Иначе учитываем оба делителя
                cnt = cnt + 2;
        }
    }
    return cnt;
}

// Функция для подсчета количества уникальных k
int findUniqueK(int a, int b, int l) {
    // Сначала подсчитаем общее количество делителей l
    int totalDivisors = countDivisors(l);

    // Теперь найдем общие делители для a и b, чтобы исключить их из общего количества
    int commonDivisors = countDivisors(__gcd(a, b));

    // Количество уникальных k будет равно общему количеству делителей минус общие делители a и b
    return totalDivisors - commonDivisors;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, l;
        cin >> a >> b >> l;
        cout << findUniqueK(a, b, l) << endl;
    }
    return 0;
}
