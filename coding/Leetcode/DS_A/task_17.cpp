// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Created by omega515 on 06.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(string digits, string ans,
                      vector<string> &answer,
                      int idx,
                      unordered_map<char, vector<char>> mp
    ) {
        if (ans.size() == digits.size()) {
            answer.push_back(ans);
            return;
        }

        char digit, ch;
        for (int i = idx; i < digits.size(); ++i) {
            digit = digits[i];
            vector<char> v = mp[digit];
            for (int j = 0; j < v.size(); ++j) {
                ch = v[j];
                ans.push_back(ch);
                backtracking(digits, ans, answer, i + 1, mp);
                ans.pop_back();
            }

        }
    }

    vector<string> letterCombinations(string digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<string> answer;
        if (digits.size() == 0) {
            return answer;
        }
        unordered_map<char, vector<char>> mp{
                {'2', {'a', 'b', 'c'}},
                {'3', {'d', 'e', 'f'}},
                {'4', {'g', 'h', 'i'}},
                {'5', {'j', 'k', 'l'}},
                {'6', {'m', 'n', 'o'}},
                {'7', {'p', 'q', 'r', 's'}},
                {'8', {'t', 'u', 'v'}},
                {'9', {'w', 'x', 'y', 'z'}}

        };
        string ans = "";
        backtracking(digits, ans, answer, 0, mp);

        return answer;
    }
};

int main() {
    string digits;
    vector<string> answer;
    Solution solve;

    digits = "";
    answer = {};
    assert(answer == solve.letterCombinations(digits));

    digits = "23";
    answer = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(answer == solve.letterCombinations(digits));

    digits = "2";
    answer = {"a", "b", "c"};
    assert(answer == solve.letterCombinations(digits));

    return 0;
}
