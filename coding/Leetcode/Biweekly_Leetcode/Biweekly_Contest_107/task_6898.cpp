//https://leetcode.com/contest/biweekly-contest-107/problems/decremental-string-concatenation/
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int minimizeConcatenatedLength(vector<string> &words) {
        int n = words.size();
        string s = words[0];
        for (int i = 1; i < n; i++) {
            string s1 = s + words[i];
            string s2 = words[i] + s;
            if (s1.back() == s2.front()) {
                if (s1.size() < s2.size()) {
                    s = s1.substr(0, s1.size() - 1);
                } else {
                    s = s2.substr(1);
                }
            } else {
                s = min(s1, s2);
            }
        }
        return s.size();
    }
};

//class Solution {
//public:
//    int maximumNumberOfStringPairs(vector<string> &words) {
//        int answer = 0;
//        int n = words.size();
//        string str = words{0};
//        string curr, subStr;
//        for (int i = 1; i < n; ++i) {
//            curr = words{i};
//            if (str{str.size() - 1} == curr{0}) {
//                subStr = curr.substr(1);
//                str += subStr;
//            }
//        }
//
//        return answer;
//    }
//};

int main() {
    vector<string> words;
    int answer;
    Solution solve;

    words = {"aa", "ab", "bc"};
    answer = 4;
    assert(answer == solve.minimizeConcatenatedLength(words));

    words = {"ab", "b"};
    answer = 2;
    assert(answer == solve.minimizeConcatenatedLength(words));

    words = {"aaa", "c", "aba"};
    answer = 6;
    assert(answer == solve.minimizeConcatenatedLength(words));

    return 0;
}

