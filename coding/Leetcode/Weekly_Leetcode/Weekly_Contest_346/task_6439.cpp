// https://leetcode.com/contest/weekly-contest-346/problems/minimum-string-length-after-removing-substrings/
// Created by Ruslan Khalikov on 21.05.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        string s1 = "AB";
        string s2 = "CD";
        while (true) {
            size_t start1 = s.find(s1);
            bool label1 = false;
            if (start1 == -1) {
                label1 = true;
            } else {
                s.replace(start1, s1.size(), "");
            }

            size_t start2 = s.find(s2);
            bool label2 = false;
            if (start2 == -1) {
                label2 = true;
            } else {
                s.replace(start2, s2.size(), "");
            }

            if (label1 && label2) {
                break;
            }
        }

        int answer = s.size();
        return answer;
    }
};

int main() {
    string s;
    int answer;
    Solution solve;

    s = "ABFCACDB";
    answer = 2;
    assert(solve.minLength(s) == answer);

    s = "ACBBD";
    answer = 5;
    assert(solve.minLength(s) == answer);

    return 0;
}
