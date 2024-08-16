// https://leetcode.com/contest/biweekly-contest-135/problems/find-the-winning-player-in-coin-game/
// Created by omega515 on 20.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "Alice";
        int dx = x;
        int dy = y / 4;
        int d = min(dx, dy);
        if (d % 2 == 0) {
            answer = "Bob";
        }

        return answer;
    }
};

int main() {
    int x, y;
    string answer;
    Solution solve;

    x = 2, y = 7;
    answer = "Alice";
    assert(answer == solve.losingPlayer(x, y));

    x = 4, y = 11;
    answer = "Bob";
    assert(answer == solve.losingPlayer(x, y));

    return 0;
}
