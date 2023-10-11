// https://leetcode.com/problems/word-ladder/description/
// Created by ruslan515 on 06.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int answer = 0;
        set<string> stWords(wordList.begin(), wordList.end());
        if (stWords.find(endWord) == stWords.end()) {
            return answer;
        }
        int n = beginWord.size();
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        set<string> visited;

        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                auto [currentWord, dist] = q.front();
                q.pop();
                if (currentWord == endWord) {
                    return dist;
                }
                visited.insert(currentWord);
                string temp;
                for (int j = 0; j < n; ++j) {
                    for (char lt = 'a'; lt <= 'z'; ++lt) {
                        temp = currentWord;
                        temp[j] = lt;
                        bool isVisited = visited.find(temp) != visited.end();
                        if (!isVisited && stWords.find(temp) != stWords.end()) {
                            q.push(make_pair(temp, dist + 1));
                        }
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    string beginWord, endWord;
    vector<string> wordList;
    int answer;
    Solution solve;

    beginWord = "ymain", endWord = "oecij", wordList = {"ymann", "yycrj", "oecij", "ymcnj", "yzcrj", "yycij", "xecij",
                                                        "yecij", "ymanj", "yzcnj", "ymain"};
    answer = 10;
    assert(answer == solve.ladderLength(beginWord, endWord, wordList));

    beginWord = "hit", endWord = "cog", wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    answer = 5;
    assert(answer == solve.ladderLength(beginWord, endWord, wordList));

    beginWord = "hit", endWord = "cog", wordList = {"hot", "dot", "dog", "lot", "log"};
    answer = 0;
    assert(answer == solve.ladderLength(beginWord, endWord, wordList));

    return 0;
}