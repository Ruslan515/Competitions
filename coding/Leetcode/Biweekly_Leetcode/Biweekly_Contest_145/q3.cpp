// https://leetcode.com/contest/biweekly-contest-145/problems/digit-operations-to-make-two-integers-equal/description/
// Created by omega515 on 07.12.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int minOperations(int n, int m) {
        if (n == m) return 0;
        if (isPrime(n) || isPrime(m)) return -1;

        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({n, 0});
        visited.insert(n);

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            string numStr = to_string(curr);

            for (int i = 0; i < numStr.length(); ++i) {
                char original = numStr[i];

                // Увеличиваем цифру
                if (numStr[i] < '9') {
                    numStr[i]++;
                    int next = stoi(numStr);
                    if (!isPrime(next) && !visited.count(next)) {
                        if (next == m) return steps + next + curr;
                        visited.insert(next);
                        q.push({next, steps + next + curr});
                    }
                    numStr[i] = original;
                }

                // Уменьшаем цифру
                if (original > '0') {
                    numStr[i]--;
                    int next = stoi(numStr);
                    if (!isPrime(next) && !visited.count(next)) {
                        if (next == m) return steps + next + curr;
                        visited.insert(next);
                        q.push({next, steps + next + curr});
                    }
                    numStr[i] = original;
                }
            }
        }

        return -1;
    }
};



int main() {
    int n, m;
    int answer;
    Solution solve;

    n = 15, m = 88;
    answer = 490;
    assert(answer == solve.minOperations(n, m));

    n = 10, m = 12;
    answer = 85;
    assert(answer == solve.minOperations(n, m));

    n = 4, m = 8;
    answer = -1;
    assert(answer == solve.minOperations(n, m));

    n = 6, m = 2;
    answer = -1;
    assert(answer == solve.minOperations(n, m));

    return 0;
}
