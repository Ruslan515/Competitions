// https://leetcode.com/contest/weekly-contest-341/problems/minimum-additions-to-make-valid-string/
// Created by ruslan515 on 16.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int i = 0;
        string valid = "abc";
        int size_valid = 3;
        int answer = 0;
        while (i < n) {
            int temp = 0;
            if (word[i] == 'a') {
                if (word[i + 1] == 'b') {
                    if (word[i + 2] == 'c') {
                        temp = 0;
                        i += 3;
                    } else {
                        temp = 1;
                        i += 2;
                    }
                } else if (word[i + 1] == 'c') {
                    temp = 1;
                    i += 2;
                } else {
                    temp = 2;
                    i += 1;
                }
            } else if (word[i] == 'b') {
                if (word[i + 1] == 'c') {
                    temp = 1;
                    i += 2;
                } else {
                    temp = 2;
                    i += 1;
                }
            } else if (word[i] == 'c') {
                temp = 2;
                i += 1;
            }
            answer += temp;
        }

        return answer;
    }

//    int addMinimum(string word) {
//        int n = word.size();
//        int i = 0;
//        string valid = "abc";
//        int size_valid = 3;
//        int answer = 0;
//        while (i < n) {
//            int j = 0;
//            while (j < size_valid && word[i] != valid[j]) {
//                ++j;
//            }
//
//            answer += j;
//
//            while (j < size_valid && i < n && word[i] == valid[j]) {
//                ++j;
//                ++i;
//            }
//            int count = 0;
//            while (j < size_valid && word[i] != valid[j]) {
//                ++j;
//                ++count;
//            }
//            answer += count;
//        }
//
//        return answer;
//    }
};


int main() {
    string word;
    int answer;
    Solution solve;

    word = "aabb";
    answer = 5;
    assert(solve.addMinimum(word) == answer);

    word = "aaaabb";
    answer = 9;
    assert(solve.addMinimum(word) == answer);

    word = "ac";
    answer = 1;
    assert(solve.addMinimum(word) == answer);

    word = "aaaaac";
    answer = 9;
    assert(solve.addMinimum(word) == answer);

    word = "b";
    answer = 2;
    assert(solve.addMinimum(word) == answer);


    word = "aaa";
    answer = 6;
    assert(solve.addMinimum(word) == answer);


    word = "abc";
    answer = 0;
    assert(solve.addMinimum(word) == answer);

    return 0;
}