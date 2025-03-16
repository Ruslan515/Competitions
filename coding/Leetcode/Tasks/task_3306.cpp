// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10
// Created by omega515 on 10.03.2025.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;


        return answer;
    }
};

int main() {
    string word;
    int k;
    ll answer;
    Solution solve;

    word = "aeioqq", k = 1;
    answer = 0;
    assert(answer == solve.countOfSubstrings(word, k));

    word = "aeiou", k = 0;
    answer = 1;
    assert(answer == solve.countOfSubstrings(word, k));

    word = "ieaouqqieaouqq", k = 1;
    answer = 3;
    assert(answer == solve.countOfSubstrings(word, k));

    return 0;
}

