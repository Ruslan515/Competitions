// https://leetcode.com/problems/path-crossing/
// Created by ruslan515 on 19.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpCount;
        for (char ch: s) {
            ++mpCount[ch];
        }
        map<int, vector<char>> mpReverse;
        char key;
        int value;
        for (auto el: mpCount) {
            key = el.first;
            value = el.second;
            mpReverse[value].push_back(key);
        }
        string answer = "";
        int count;
        map<int, vector<char>>::reverse_iterator it = mpReverse.rbegin();
        for (; it != mpReverse.rend(); ++it) {
            count = it->first;
            vector<char> val = it->second;
            for (char ch: val) {
                for (int i = 0; i < count; ++i) {
                    answer += ch;
                }
            }
        }

        return answer;
    }
};

int main() {
    string s;
    string answer;
    Solution solve;

    s = "Aabb";
    answer = "bbaA";
    assert(answer == solve.frequencySort(s));

    s = "tree";
    answer = "eert";
    assert(answer == solve.frequencySort(s));

    s = "cccaaa";
    answer = "aaaccc";
    assert(answer == solve.frequencySort(s));


    return 0;
}
