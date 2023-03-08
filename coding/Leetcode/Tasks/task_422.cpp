// https://leetcode.com/problems/kth-missing-positive-number/
// Created by ruslan515 on 06.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        bool answer = true;
        int n = words.size();
        string curr_word;
        for (int i = 0; i < n; ++i) {
            curr_word = words[i];
            string temp = "";
            int m = curr_word.size();
            if (m > n) {
                answer = false;
                return answer;
            }
            for (int j = 0; j < m; ++j) {
                char ch;
                ch = words[j][i];
                if (ch != curr_word[j]) {
                    answer = false;
                    return answer;
                }
            }
        }

        return answer;
    }

//    bool validWordSquare(vector<string>& words) {
//        bool answer = true;
//        int n = words.size();
//        string curr_word;
//        for (int i = 0; i < n; ++i) {
//            curr_word = words[i];
//            string temp = "";
//            int m = curr_word.size();
//            for (int j = 0; j < n; ++j) {
//                char ch;
//                if (j >= m) {
//                    ch = '#';
//                    curr_word += ch;
//                } else {
//                    ch = words[j][i];
//                }
//
//                temp += ch;
//            }
//            if (curr_word != temp) {
//                answer = false;
//                break;
//            }
//        }
//
//        return answer;
//    }
};

void read_data(vector<string>& words) {
    string t;
    while (cin >> t)
        words.push_back(t);
    return;
}

int main() {
    vector<string> words;
    read_data(words);
    Solution solve;
    cout << solve.validWordSquare(words);

    return 0;
}
