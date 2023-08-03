// https://leetcode.com/problems/removing-stars-from-a-string/description/
// Created by Ruslan Khalikov on 01.08.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        vector<char> stack;
        for (char ch: s) {
            if (!stack.empty() && ch == '*') {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }

        }

        string answer(stack.begin(), stack.end());
        return answer;
    }
};

int main() {
    string s, answer;
    Solution solve;

    s = "leet**cod*e";
    answer =  "lecoe";
    assert(answer == solve.removeStars(s));

    s = "erase*****";
    answer =  "";
    assert(answer == solve.removeStars(s));

    return 0;
}