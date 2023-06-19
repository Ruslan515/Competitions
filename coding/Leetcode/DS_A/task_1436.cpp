// https://leetcode.com/problems/destination-city/
// Created by ruslan515 on 19.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_map<string, string> mp;
        for (vector<string> ab: paths) {
            mp[ab[0]] = ab[1];
        }
        string from, to;
        from = paths[0][0];
        to = mp[from];
        while (mp.find(to) != mp.end()) {
            from = to;
            to = mp[from];
        }
        return to;
    }
};

int main() {
    vector<vector<string>> paths;
    string answer;
    Solution solve;

    paths = {{"London",   "New York"},
             {"New York", "Lima"},
             {"Lima",     "Sao Paulo"}};
    answer = "Sao Paulo";
    assert(answer == solve.destCity(paths));

    paths = {{"B", "C"},
             {"D", "B"},
             {"C", "A"}};
    answer = "A";
    assert(answer == solve.destCity(paths));

    return 0;
}
