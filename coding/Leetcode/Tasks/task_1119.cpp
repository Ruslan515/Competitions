// https://leetcode.com/problems/remove-vowels-from-a-string/
// Created by ruslan515 on 14.01.23.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeVowels(string s) {
        string chars = "aeiou";
        for(char& c: chars) {
            auto char_dels = remove(s.begin(), s.end(), c);
            s.erase(char_dels, s.end());
        }
        return s;
    }
};

void read_data(string& s) {
    cin >> s;
    return;
}

int main() {
    string s;
    read_data(s);
    Solution solve;
    cout << solve.removeVowels(s);

    return 0;
}