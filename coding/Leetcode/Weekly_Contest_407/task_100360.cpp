// https://leetcode.com/contest/weekly-contest-407/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/
// Created by omega515 on 21.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int operations = 0; // для подсчета количества возможных операций
        int oneCount = 0;   // для подсчета количества единиц, которые можно переместить вправо

        // Проходим строку слева направо, начиная с индекса 1
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0' && s[i - 1] == '1') {
                operations += oneCount; // увеличиваем количество операций на количество единиц, которые можно переместить вправо
            }
            if (s[i] == '1') {
                oneCount++; // увеличиваем счетчик единиц, которые можно переместить вправо
            }
        }

        return operations;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "1001101";
    answer = 4;
    assert(answer == solve.maxOperations(s));

    s = "00111";
    answer = 0;
    assert(answer == solve.maxOperations(s));

    return 0;
}
