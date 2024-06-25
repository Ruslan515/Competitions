// https://leetcode.com/problems/perform-string-shifts/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 21.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>> &shift) {
        string answer;
        int n = s.size();
        int cnt = shift.size();
        int from, direction;
        string sCopy;
        for (int i = 0; i < cnt; ++i) {
            direction = shift[i][0] == 0 ? -1 : 1;
            int shifts = shift[i][1];
            sCopy = s;
            for (int j = 0; j < n; ++j) {
                from = j + direction * shifts;
                if (from < 0) {
                    from = n + ();
                }
                from = from % n;
                sCopy[from] = s[j];
            }
            s = sCopy;
        }
        answer = s;

        return answer;
    }
};

int main() {
    string s;
    vector<vector<int>> shift;
    string answer;
    Solution solve;

    s = "abc", shift = {{0, 4}};
    answer = "bca";
    assert(answer == solve.stringShift(s, shift));

    s = "abc", shift = {{0, 1},
                        {1, 2}};
    answer = "cab";
    assert(answer == solve.stringShift(s, shift));

    s = "abcdefg", shift = {{1, 1},
                            {1, 1},
                            {0, 2},
                            {1, 3}};
    answer = "efgabcd";
    assert(answer == solve.stringShift(s, shift));

    return 0;
}

