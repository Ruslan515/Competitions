// https://leetcode.com/contest/weekly-contest-373/problems/count-beautiful-substrings-i/
// Created by omega515 on 26.11.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int answer = 0;

        return answer;
    }
};

int main() {
    string s;
    int k;
    int answer;
    Solution solve;

    s = "baeyh", k = 2;
    answer = 2;
    assert(answer == solve.beautifulSubstrings(s, k));

    s = "abba", k = 1;
    answer = 3;
    assert(answer == solve.beautifulSubstrings(s, k));

    s = "bcdf", k = 1;
    answer = 0;
    assert(answer == solve.beautifulSubstrings(s, k));

    return 0;
}

