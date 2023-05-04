// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Created by ruslan515 on 02.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getComb(string &str_digits, vector<int> &comb, int k) {
        string ans = "";
        for (int i = 0; i < k; ++i) {
            int idx = comb[i];
            char temp = str_digits[idx];
            ans += temp;
        }
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if (digits == "") {
            return answer;
        }
        map<char, string> mp_digits = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        if (digits.size() == 1) {
            for (char ch: mp_digits[digits[0]]) {
                answer.push_back(to_string(ch));
            }
        }
        string str_digits = "";
        for (auto ch: digits) {
            str_digits += mp_digits[ch];
        }

        int k = digits.size();
        int n = str_digits.size();
        vector<int> comb;
        for (int i = 0; i < k; ++i) {
            comb.push_back(i);
        }
        comb.push_back(n);
        comb.push_back(0);
        while (true) {
            string ans = getComb(str_digits, comb, k);
            answer.push_back(ans);
            for (int i = 0; i < k + 1; ++i) {
                if (comb[i] + 1 == comb[i + 1]) {
                    comb[i] = i;
                } else {
                    break;
                }
                if (i < k) {
                    ++comb[i];
                } else {
                    break;
                }
            }
        }

    }
};

int main() {
    vector<string> answer;
    string digits;
    Solution solve;

    digits = "23";
    answer = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(solve.letterCombinations(digits) == answer);

    digits = "";
    answer = {};
    assert(solve.letterCombinations(digits) == answer);

    digits = "2";
    answer = {"a", "b", "c"};
    assert(solve.letterCombinations(digits) == answer);

    return 0;
}