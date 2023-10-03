// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/?envType=daily-question&envId=2023-10-02
// Created by ruslan515 on 02.10.23.
//

// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-i/
// Created by ruslan515 on 01.10.23.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool winnerOfGame(string colors) {
        bool answer = false;
        int n = colors.size();
        if (n < 3) {
            return answer;
        }
        int countA = 0, countB = 0;

        for (int i = 1; i < n - 1; ++i) {
            char x = colors[i - 1], y = colors[i], z = colors[i + 1];
            if (x == y && y == z) {
                if (x == 'A') {
                    countA++;
                } else {
                    countB++;
                }
            }
        }
        if (countA > countB) {
            answer = true;
        }
        return answer;
    }
};

int main() {
    string colors;
    bool answer;
    Solution solve;

    colors = "AAABABB";
    answer = true;
    assert(answer == solve.winnerOfGame(colors));

    colors = "AA";
    answer = false;
    assert(answer == solve.winnerOfGame(colors));

    colors = "ABBBBBBBAAA";
    answer = false;
    assert(answer == solve.winnerOfGame(colors));

    return 0;
}
