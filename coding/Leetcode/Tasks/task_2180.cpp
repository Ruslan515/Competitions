// https://leetcode.com/problems/count-integers-with-even-digit-sum/
// Created by ruslan515 on 20.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calc(int x){
        int x1 = x / 10;
        int x2 = x % 10;
        return x1 + x2;
    }
    int countEven(int num) {
        int answer = 0;
        if (num == 1000) {
            answer += (num / 10 - 1) * 5 + 4;
            return answer;
        }

        int x = num / 10;
        if (x > 1) {
            answer += (x - 1) * 5;
        }
        int d = num % 10;
        if (d == 0) {
            if (x >= 10) {

                int s = calc(x);
                if (s % 2 == 0) {
                    ++answer;
                }
            } else {
                if (x % 2 == 0) {
                    answer += 1;
                }
            }

        } else if (d != 0) {
            int i = 0;
            int s = calc(x);
            if (s % 2 != 0) {
                i = 1;
            }
            int count = 0;
            while (i <= d) {
                i += 2;
                ++count;
            }
            if (num < 10) {
                --count;
            }
            answer += count;
        }
        if (num >= 10) {
            answer += 4;
        }
        return answer;
    }
};

int main() {
    int num;
    int answer;
    Solution solve;

    num = 1000;
    answer = 499;
    assert(solve.countEven(num) == answer);

    num = 158;
    answer = 79;
    assert(solve.countEven(num) == answer);

    num = 910;
    answer = 455;
    assert(solve.countEven(num) == answer);

    num = 38;
    answer = 18;
    assert(solve.countEven(num) == answer);

    num = 26;
    answer = 13;
    assert(solve.countEven(num) == answer);

    num = 20;
    answer = 10;
    assert(solve.countEven(num) == answer);

    num = 13;
    answer = 6;
    assert(solve.countEven(num) == answer);

    num = 4;
    answer = 2;
    assert(solve.countEven(num) == answer);

    num = 30;
    answer = 14;
    assert(solve.countEven(num) == answer);

    num = 10;
    answer = 4;
    assert(solve.countEven(num) == answer);

    return 0;
}