// https://leetcode.com/problems/add-digits/
// Created by ruslan515 on 19.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int answer = 0;
        while (true) {
            string temp = to_string(num);
            int sum = 0;
            for (auto digit: temp) {
                int x = digit - '0';
                sum += x;
            }
            if (sum < 10) {
                answer = sum;
                break;
            } else {
                num = sum;
            }
        }
        return answer;
    }
};

int main() {
    int num, answer;
    Solution solve;

    num = 38;
    answer = 2;
    assert(solve.addDigits(num) == answer);

    num = 0;
    answer = 0;
    assert(solve.addDigits(num) == answer);

    return 0;
}