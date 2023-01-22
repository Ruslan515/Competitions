// https://leetcode.com/problems/valid-anagram/description/
// Created by ruslan515 on 22.01.23.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void make_map(string s, map<char, int>& mp) {
        for (char c: s) {
            if (mp.count(c) == 0) {
                mp[c] = 1;
            } else {
                ++mp[c];
            }
        }
        return;
    }

    bool isAnagram(string s, string t) {
        bool ans = true;
        if (s.size() != t.size()) {
            ans = false;
            return ans;
        }
        map<char, int> mp;
        make_map(t, mp);

        for (char c: s) {
            if (mp.count(c) == 0) {
                ans = false;
                break;
            } else if (--mp[c] < 0) {
                ans = false;
                break;
            }
        }


        return ans;
    }
};

void read_data(string& s, string& t) {
    cin >> s >> t;
    return;
}

int main() {
    string s, t;
    read_data(s, t);
    Solution solve;
    cout << solve.isAnagram(s, t);
    return 0;
}