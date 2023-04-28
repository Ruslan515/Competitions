// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
// Created by ruslan515 on 19.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int answer = 0;
        string temp = "";
        for (auto ch: s) {
            int x = (int)ch - 96;
            string x_string = to_string(x);
            temp += x_string;
        }

        for (int i = 0; i < k; ++i) {
            answer = 0;
            for (char ch: temp) {
                int x = ch - '0';
                answer += x;
            }
            temp = to_string(answer);
        }

        return answer;
    }
};

int main() {
    string s;
    int k, answer;
    Solution solve;

//    s = "iiii", k = 1;
//    answer = 36;
//    assert(solve.getLucky(s, k) == answer);

    s = "leetcode", k = 2;
    answer = 6;
    assert(solve.getLucky(s, k) == answer);


    return 0;
}