// https://leetcode.com/problems/first-unique-character-in-a-string/
// Created by ruslan515 on 21.01.23.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        map <char, pair<int, int>> map_my;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (map_my.count(c) == 0) {
                pair<int, int> p = make_pair(i, 1);
                map_my[c] = p;
            } else {
                ++map_my[c].second;
            }
        }

        map <char, pair<int, int>> :: iterator it = map_my.begin();
        int min_idx = s.size() + 1;
        for (int i = 0; it != map_my.end(); it++) {
            pair<int, int> val = it->second;
            int cnt = val.second;
            int idx = val.first;
            if (cnt == 1) {
                min_idx = min(min_idx, idx);
            }
        }
        if (min_idx != s.size() + 1) {
            ans = min_idx;
        }

        return ans;
    }
};

void read_data(string& s) {
    cin >> s;
}

int main() {
    string s;
    read_data(s);
    Solution solve;
    cout << solve.firstUniqChar(s);
    return 0;
}