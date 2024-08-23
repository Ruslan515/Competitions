// https://leetcode.com/problems/guess-number-higher-or-lower/description/
// Created by omega515 on 20.08.24.
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int pick;

int guess(int num) {
    int answer = 0;
    if (num > pick) {
        answer = -1;
    } else if (num < pick) {
        answer = 1;
    }
    return answer;
}

class Solution {
public:
    int guessNumber(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int left = 0, right = n;
        int middle;
        int temp;
        while (left <= right) {
            middle = left + (right - left) / 2;
            temp = guess(middle);
            if (temp == 0) {
                break;
            } else if (temp == -1) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return middle;
    }
};

int main() {
    int n;

    int answer;

    Solution solve;

    n = 10;
    pick = 6;
    answer = 6;
    assert(answer == solve.guessNumber(n));

    return 0;
}
