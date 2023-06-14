// https://leetcode.com/problems/group-anagrams/
// Created by ruslan515 on 14.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> answer;
        map<map<char, int>, vector<string>> mpStr;

        for (auto word: strs) {
            map<char, int> mp;
            for (char ch: word) {
                ++mp[ch];
            }
            mpStr[mp].push_back(word);
        }

        for(pair<map<char, int>, vector<string>> el: mpStr) {
            answer.push_back(el.second);
        }

        return answer;
    }
};

int main() {
    vector<string> strs;
    vector<vector<string>> answer;
    Solution solve;

//    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//    answer = {{"bat"},
//              {"nat", "tan"},
//              {"ate", "eat", "tea"}};
//    assert(answer == solve.groupAnagrams(strs));

    strs = {""};
    answer = {{""}};
    assert(answer == solve.groupAnagrams(strs));

    strs = {"a"};
    answer = {{"a"}};
    assert(answer == solve.groupAnagrams(strs));

    return 0;
}
