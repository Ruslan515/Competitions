// https://leetcode.com/problems/single-row-keyboard/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 02.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<char, int> mp;
        int n = 26;
        for (int i = 0; i < n; ++i) {
            mp[keyboard[i]] = i;
        }
        int m = word.size();
        int prev = 0, diff, curr;
        for (int i = 0; i < m; ++i) {
            curr = mp[word[i]];
            diff = abs(prev - curr);
            answer += diff;
            prev = curr;
        }

        return answer;
    }
};

int main() {
    string keyboard, word;
    int answer;
    Solution solve;


    keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba";
    answer = 4;
    assert(answer == solve.calculateTime(keyboard, word));

    keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode";
    answer = 73;
    assert(answer == solve.calculateTime(keyboard, word));

    return 0;
}
