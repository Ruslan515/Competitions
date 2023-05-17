// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Created by ruslan515 on 15.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int base = 16;

    string toHex(int num) {
        map<int, char> mpHex = {{10, 'a'},
                                {11, 'b'},
                                {12, 'c'},
                                {13, 'd'},
                                {14, 'e'},
                                {15, 'f'}};
        if (num == 0) {
            return "0";
        }
        string answer = "";

        unsigned n = num;

        vector<int> temp;
        while (n != 0) {
            int d = n % base;
            temp.push_back(d);
            n /= base;
        }

        while (!temp.empty()) {
            int x = temp.back();
            temp.pop_back();
            char ch;
            if (mpHex.count(x)) {
                ch = mpHex[x];
            } else {
                ch = x + '0';
            }
            answer += ch;
        }

        return answer;
    }
};

int main() {
    int num;
    string answer;
    Solution solve;

    num = 26;
    answer = "1a";
    assert(solve.toHex(num) == answer);

    num = -1;
    answer = "ffffffff";
    assert(solve.toHex(num) == answer);

    return 0;
}