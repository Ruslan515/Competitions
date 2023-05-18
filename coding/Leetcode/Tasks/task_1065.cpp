// https://leetcode.com/problems/index-pairs-of-a-string/
// Created by ruslan515 on 18.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string> &words) {
        vector<vector<int>> answer;
        int n = text.size();
        for (string word: words) {
            int size = word.size();
            int end;
            for (int start = 0; start < n - size + 1; ++start) {
                if (text[start] != word[0]) {
                    continue;
                }
                int i = start;

                int j = 0;
                while (i < n && text[i] == word[j]) {
                    ++i;
                    ++j;
                }
                if (j == size) {
                    end = i - 1;
                    answer.push_back({start, end});
                }
            }
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    vector<vector<int>> answer;
    vector<string> words;
    string text;
    Solution solve;

//    text = "thestoryofleetcodeandme", words = {"story", "fleet", "leetcode"};
//    answer = {{3,  7},
//              {9,  13},
//              {10, 17}};
//    assert(solve.indexPairs(text, words) == answer);

    text = "ababa", words = {"aba", "ab"};
    answer = {{0, 1},
              {0, 2},
              {2, 3},
              {2, 4}};
    assert(solve.indexPairs(text, words) == answer);

    return 0;
}