// https://leetcode.com/contest/weekly-contest-381/problems/minimum-number-of-pushes-to-type-word-i/
// Created by omega515 on 21.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int answer = 0;
        int n = word.size();
        if (n <= 8) {
            answer = n;
        } else {
            int d = n / 8;
            int tmp = 0;
            for (int i = 0; i < d; ++i) {
                tmp += (i + 1) * 8;
            }
            int k = n % 8;
            int diff = k * (d + 1);
            answer = tmp + diff;
        }

        return answer;
    }
};

int main() {
    string word;
    int answer;
    Solution solve;

    word = "abcdefghijklmnop";
    answer = 24;
    assert(answer == solve.minimumPushes(word));

    word = "abcde";
    answer = 5;
    assert(answer == solve.minimumPushes(word));

    word = "xycdefghij";
    answer = 12;
    assert(answer == solve.minimumPushes(word));

    return 0;
}

