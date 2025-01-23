// https://leetcode.com/contest/weekly-contest-337/problems/number-of-even-and-odd-bits/
// Created by ruslan515 on 19.03.23.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> evenOddBit(int n) {
        string s = bitset<16>(n).to_string();
        int even = 0;
        int odd = 0;
        int size = s.size();
        for (int i = size - 1; i > -1; --i) {
            char ch = s[i];
            if (ch == '1') {
                if ((size - 1 - i) % 2 == 0)
                {
                    ++even;
                } else {
                    ++odd;
                }
            }
        }

        vector<int> answer = {even, odd};

        return answer;
    }
};


int main() {
    Solution solve;
    int n = 2;
    vector<int>  answer = solve.evenOddBit(n);
    for (int a: answer) {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}