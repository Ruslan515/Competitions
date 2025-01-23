// https://leetcode.com/contest/biweekly-contest-119/problems/remove-adjacent-almost-equal-characters/
// Created by ruslan515 on 09.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int answer;

        return answer;
    }
};

int main() {
    string word;
    int answer;
    Solution solve;

    word = "aaaaa";
    answer = 2;
    assert(answer == solve.removeAlmostEqualCharacters(word));

    word = "abddez";
    answer = 2;
    assert(answer == solve.removeAlmostEqualCharacters(word));

    word = "zyxyxyz";
    answer = 3;
    assert(answer == solve.removeAlmostEqualCharacters(word));

    return 0;
}

