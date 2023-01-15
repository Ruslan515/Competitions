// https://leetcode.com/problems/single-row-keyboard/
// Created by ruslan515 on 23.12.22.
//

#include <iostream>
#include <map>

using namespace std;

//class Solution {
//public:
//    int calculateTime(string keyboard, string word) {
//        int ans = 0;
//        map <char, int> dict;
//        for (int i = 0; i < keyboard.size(); ++i)
//            dict.insert(make_pair(keyboard[i], i));
//
//        int start_idx = 0;
//        int count = 0;
//        for (int i = 0; i < word.size(); ++i) {
//            char temp = word[i];
//            int delta = dict[temp];
//            delta = abs(start_idx - delta);
//            count += delta;
//            start_idx = dict[temp];
//        }
//        ans = count;
//
//        return ans;
//    }
//};

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int ans = 0;

        int start_idx = 0;
        int count = 0;
        for (int i = 0; i < word.size(); ++i) {
            char temp = word[i];
            int idx = keyboard.find(temp);
            int delta = abs(start_idx - idx);
            count += delta;
            start_idx = idx;
        }
        ans = count;

        return ans;
    }
};

void read_data(string& keyboard, string& word) {
    cin >> keyboard >> word;
    return;
}

int main() {
    string keyboard;
    string word;
    read_data(keyboard, word);
    Solution s;
    std::cout << s.calculateTime(keyboard, word);
    return 0;
}