// https://leetcode.com/contest/weekly-contest-349/problems/neither-minimum-nor-maximum/
// Created by Ruslan Khalikov on 11.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int start = 0;
        if (s[0] == 'a') {
            while (start < n && s[start] == 'a') {
                ++start;
            }
            if (start == n) {
                char temp = 'z';
                s[n - 1] = temp;
            } else {
                char temp;
                while (start < n && s[start] != 'a') {
                    temp = s[start];
                    --temp;
                    s[start] = temp;
                    ++start;
                }

            }

        } else {
            char temp;
            while (start < n && s[start] != 'a') {
                temp = s[start];
                --temp;
                s[start] = temp;
                ++start;
            }
        }

        return s;
    }
};

int main() {
    string s;
    string answer;
    Solution solve;

    s = "aa";
    answer = "az";
    assert(answer == solve.smallestString(s));

    s = "a";
    answer = "z";
    assert(answer == solve.smallestString(s));

    s = "aaaaa";
    answer = "aaaaz";
    assert(answer == solve.smallestString(s));


    s = "cbabc";
    answer = "baabc";
    assert(answer == solve.smallestString(s));

    s = "acbbc";
    answer = "abaab";
    assert(answer == solve.smallestString(s));

    s = "leetcode";
    answer = "kddsbncd";
    assert(answer == solve.smallestString(s));

    return 0;
}
