// https://leetcode.com/contest/weekly-contest-367/problems/shortest-and-lexicographically-smallest-beautiful-string/
// Created by ruslan515 on 15.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkLex(string temp, string answer) {
        bool check = false;
        int i = 0;
        int n = temp.size();
        while (i < n && temp[i] == answer[i]) {
            ++i;
        }
        if (temp[i] == '1') {
            check = true;
        }
        return check;
    }

    string shortestBeautifulSubstring(string s, int k) {
        string answer = "";
        int left = 0, right = 0;
        string currentMax = "";
        int lenShort = 0;
        int lenCurr;
        int n = s.size();
        int count = 0;
        while (right < n) {
            while (right < n && count < k) {
                if (s[right] == '1') {
                    count++;
                }
                right++;
            }
            lenCurr = right - left;
            if (lenShort == 0 || lenCurr < lenShort) {
                lenShort = lenCurr;
                answer = s.substr(left, lenCurr);
            } else if (lenCurr == lenShort) {
                string temp = s.substr(left, lenCurr);
                if (temp != answer) {
                    bool check = checkLex(temp, answer);
                    if (check) {
                        answer = temp;
                    }
                }
            }
            while (right < n && s[right] == '0') {
                ++right;
            }
            while (left < n && s[left] == '1') {
                ++left;
                --count;
            }
        }

        return answer;
    }
};

int main() {
    string s, answer;
    int k;
    Solution solve;

    s = "100011001", k = 3;
    answer = "11001";
    assert(answer == solve.shortestBeautifulSubstring(s, k));

    s = "1011", k = 2;
    answer = "11";
    assert(answer == solve.shortestBeautifulSubstring(s, k));

    s = "000", k = 1;
    answer = "";
    assert(answer == solve.shortestBeautifulSubstring(s, k));

    return 0;
}

