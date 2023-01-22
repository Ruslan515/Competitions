// https://leetcode.com/problems/ransom-note/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 22.01.23.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ans = true;
        if (ransomNote.size() > magazine.size()) {
            ans = false;
            return ans;
        }
        map<char, int> mp;

        for(char c: magazine) {
            if (mp.count(c) == 0) {
                mp[c] = 1;
            } else {
                ++mp[c];
            }
        }

        for (char c: ransomNote) {
            if (mp.count(c) == 0) {
                ans = false;
                break;
            } else {
                if (--mp[c] < 0) {
                    ans = false;
                    break;
                }
            }
        }

        return ans;
    }
};

void read_data(string& ransomNote, string& magazine) {
    cin >> ransomNote;
    cin >> magazine;
    return;
}

int main() {
    string ransomNote;
    string magazine;
    read_data(ransomNote, magazine);
    Solution solve;
    cout << solve.canConstruct(ransomNote, magazine);
    return 0;
}