// https://leetcode.com/problems/base-7/description/
// Created by ruslan515 on 15.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int base = 7;

    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string answer = "";
        if (num < 0) {
            answer += '-';
        }
        vector<int> temp;
        num = abs(num);
        while (num != 0) {
            int d = num % base;
            temp.push_back(d);
            num /= base;
        }
//        temp.push_back(num);

        while (!temp.empty()) {
            int x = temp.back();
            temp.pop_back();
            char ch = x + '0';
            answer += ch;
        }

        return answer;
    }
};

int main() {
    int num;
    string answer;
    Solution solve;

    num = 100;
    answer = "202";
    assert(solve.convertToBase7(num) == answer);

    num = -7;
    answer = "-10";
    assert(solve.convertToBase7(num) == answer);

    return 0;
}