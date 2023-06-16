// https://leetcode.com/problems/jewels-and-stones/description/
// Created by ruslan515 on 16.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> setJewels;
        for (char ch: jewels) {
            setJewels.insert(ch);
        }

        int answer = 0;
        for (char ch: stones) {
            if (setJewels.count(ch)) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    string jewels, stones;
    int answer;
    Solution solve;

    jewels = "aA", stones = "aAAbbbb";
    answer = 3;
    assert(answer == solve.numJewelsInStones(jewels, stones));

    jewels = "z", stones = "ZZ";
    answer = 0;
    assert(answer == solve.numJewelsInStones(jewels, stones));

    return 0;
}