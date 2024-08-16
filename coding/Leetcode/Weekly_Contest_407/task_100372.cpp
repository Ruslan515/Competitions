// https://leetcode.com/contest/weekly-contest-407/problems/number-of-bit-changes-to-make-two-integers-equal/description/
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        if (n == k) {
            return answer;
        }
        if (n < k) {
            return -1;
        }
        int x, y;
        while (n || k) {
            x = n & 1;
            y = k & 1;
            n >>= 1;
            k >>= 1;
            if (x == y) {
                continue;
            }
            if (x == 1 && y == 0) {
                ++answer;
            } else {
                answer = -1;
                break;
            }
        }

        return answer;
    }
};

int main() {
    int n, k;
    int answer;
    Solution solve;

    n = 13, k = 4;
    answer = 2;
    assert(answer == solve.minChanges(n, k));

    n = 21, k = 21;
    answer = 0;
    assert(answer == solve.minChanges(n, k));

    n = 14, k = 13;
    answer = -1;
    assert(answer == solve.minChanges(n, k));

    return 0;
}
