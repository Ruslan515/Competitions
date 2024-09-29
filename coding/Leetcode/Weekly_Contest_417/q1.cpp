// https://leetcode.com/contest/weekly-contest-417/problems/find-the-k-th-character-in-string-game-i/description/
// Created by omega515 on 29.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        char answer;
        string word = "a";
        for (int i = 0; i < k; ++i) {
            int size = word.size();
            string tmp = "";
            for (int j = 0; j < size; ++j) {
                char ch = word[j];
                int num = ch - '0';
                ++num;
                num %= int('a') + 26;
                ch = num + '0';
                tmp += ch;
            }
            word += tmp;
            size = word.size();
            if (size >= k) {
                answer = word[k - 1];
                break;
            }
        }

        return answer;
    }
};

int main() {
    int k;
    char answer;
    Solution solve;

    k = 5;
    answer = 'b';
    assert(answer == solve.kthCharacter(k));

    k = 10;
    answer = 'c';
    assert(answer == solve.kthCharacter(k));

    return 0;
}
