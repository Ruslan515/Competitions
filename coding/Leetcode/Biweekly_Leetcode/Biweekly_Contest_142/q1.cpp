// https://leetcode.com/contest/biweekly-contest-142/problems/find-the-original-typed-string-i/
// Created by omega515 on 26.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        vector<int> v;
        int n = word.size();
        char first, next;
        int start, end;
        for (int i = 0; i < n - 1; ++i) {
            first = word[i];
            next = word[i + 1];
            if (first == next) {
                start = i;
                end = i + 1;
                while (first == word[end]) {
                    ++end;
                }
                int cnt = end - start;
                v.push_back(cnt);
                answer += cnt - 1;
                i = end - 1;
            }
        }
        ++answer;


        return answer;
    }
};

int main() {
    string word;
    int answer;
    Solution solve;

    word = "abbcccc";
    answer = 5;
    assert(answer == solve.possibleStringCount(word));

    word = "abcd";
    answer = 1;
    assert(answer == solve.possibleStringCount(word));

    word = "aaaa";
    answer = 4;
    assert(answer == solve.possibleStringCount(word));

    return 0;
}
