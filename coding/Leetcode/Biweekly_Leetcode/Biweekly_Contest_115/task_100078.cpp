// https://leetcode.com/contest/biweekly-contest-115/problems/longest-unequal-adjacent-groups-subsequence-i/
// Created by ruslan515 on 14.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups) {
        vector<string> answer;
        vector<int> prev(n);
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            d[i] = 1;
            prev[i] = -1;
            for (int j = 0; j < i; ++j) {
                if (groups[j] != groups[i] && d[j] + 1 > d[i]) {
                    d[i] = d[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int pos = 0;
        int length = d[0];
        for (int i = 0; i < n; ++i) {
            if (d[i] > length) {
                pos = i;
                length = d[i];
            }
        }
        while (pos != -1) {
            answer.push_back(words[pos]);
            pos = prev[pos];
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};

int main() {
    vector<string> words;
    int n;
    vector<int> groups;
    vector<string> answer;
    Solution solve;

    n = 3, words = {"e", "a", "b"}, groups = {0, 0, 1};
    answer =  { "e", "b" };
    assert(answer == solve.getWordsInLongestSubsequence(n, words, groups));

    n = 3, words = { "e", "a", "b" }, groups = { 0, 0, 1 };
    answer =  { "e", "b" };
    assert(answer == solve.getWordsInLongestSubsequence(n, words, groups));

    return 0;
    }

