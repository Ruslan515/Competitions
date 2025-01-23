// https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10
// Created by omega515 on 10.01.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<string> answer;
        int n1 = words1.size();
        int n2 = words2.size();
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < n2; ++i) {
            string s = words2[i];
            unordered_map<char, int> tmpMap;
            for (char ch: s) {
                ++tmpMap[ch];
            }
            char key;
            int val;
            for (auto const &item: tmpMap) {
                key = item.first;
                val = item.second;
                if (mp2.find(key) != mp2.end()) {
                    mp2[key] = max(mp2[key], val);
                } else {
                    mp2[key] = val;
                }
            }
        }

        for (int i = 0; i < n1; ++i) {
            string s = words1[i];
            unordered_map<char, int> tmpMap;
            for (char ch: s) {
                ++tmpMap[ch];
            }

            char key;
            int val, val1;
            answer.push_back(s);
            for (auto const &item: mp2) {
                key = item.first;
                val = item.second;
                if (tmpMap.find(key) == tmpMap.end()) {
                    answer.pop_back();
                    break;
                } else {
                    val1 = tmpMap[key];
                    if (val1 < val) {
                        answer.pop_back();
                        break;
                    }
                }
            }

        }


        return answer;
    }
};


int main() {
    vector<string> words1, words2;
    vector<string> answer;
    Solution solve;

    words1 = {"amazon", "apple", "facebook", "google", "leetcode"}, words2 = {"e", "o"};
    answer = {"facebook", "google", "leetcode"};
    assert(answer == solve.wordSubsets(words1, words2));

    words1 = {"amazon", "apple", "facebook", "google", "leetcode"}, words2 = {"l", "e"};
    answer = {"apple", "google", "leetcode"};
    assert(answer == solve.wordSubsets(words1, words2));

    return 0;
}
