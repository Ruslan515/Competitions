// https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03
// Created by omega515 on 03.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";
        int strSize = s.size();
        int spacesSize = spaces.size();
        int j = 0;
        int x = spaces[j];
        for (int i = 0; i < strSize; ++i) {
            if (i == x) {
                answer += " ";
                ++j;
                if (j < spacesSize) {
                    x = spaces[j];
                }
            }
            answer += s[i];
        }

        return answer;
    }
};


int main() {
    string s;
    vector<int> spaces;
    string answer;
    Solution solve;

    s = "LeetcodeHelpsMeLearn", spaces = {8, 13, 15};
    answer = "Leetcode Helps Me Learn";
    assert(answer == solve.addSpaces(s, spaces));

    s = "icodeinpython", spaces = {1, 5, 7, 9};
    answer = "i code in py thon";
    assert(answer == solve.addSpaces(s, spaces));

    s = "spacing", spaces = {0, 1, 2, 3, 4, 5, 6};
    answer = " s p a c i n g";
    assert(answer == solve.addSpaces(s, spaces));

    return 0;
}