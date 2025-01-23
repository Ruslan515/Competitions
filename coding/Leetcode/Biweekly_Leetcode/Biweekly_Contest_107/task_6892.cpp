//
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isReverse(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 != n2) {
            return false;
        }
        for (int i = 0; i < n1; ++i) {
            if (s1[i] != s2[n1 - i - 1]) {
                return false;
            }
        }
        return true;
    }

    int maximumNumberOfStringPairs(vector<string> &words) {
        int answer = 0;
        int n = words.size();
        string word, current;
        for (int i = 0; i < n - 1; ++i) {
            word = words[i];
            for (int j = i + 1; j < n; ++j) {
                current = words[j];
                if (isReverse(word, current)) {
                    ++answer;
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {
    vector<string> words;
    int answer;
    Solution solve;

    words = {"ip","pi"};
    answer = 1;
    assert(answer == solve.maximumNumberOfStringPairs(words));

    words = {"ny", "gz", "yr", "kt", "qd", "yn", "zg", "ry", "tk", "dq"};
    answer = 5;
    assert(answer == solve.maximumNumberOfStringPairs(words));

    words = {"cd", "ac", "dc", "ca", "zz"};
    answer = 2;
    assert(answer == solve.maximumNumberOfStringPairs(words));


    return 0;
}

