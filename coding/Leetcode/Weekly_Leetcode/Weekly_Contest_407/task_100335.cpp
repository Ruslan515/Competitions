// https://leetcode.com/contest/weekly-contest-407/problems/number-of-bit-changes-to-make-two-integers-equal/description/
// Created by omega515 on 23.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = true;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int currIdx, prevIdx = -1;
        int countVowels = 0;
        char ch;
        for (int i = 0; i < n; ++i) {
            ch = s[i];
            if (vowels.find(ch) != vowels.end()) {
                ++countVowels;
            }
        }
        if (countVowels == 0) {
            answer = false;
        }


        return answer;
    }
};

int main() {
    string s;
    bool answer;
    Solution solve;

    s = "leetcoder";
    answer = true;
    assert(answer == solve.doesAliceWin(s));

    s = "bbcd";
    answer = false;
    assert(answer == solve.doesAliceWin(s));

    return 0;
}
