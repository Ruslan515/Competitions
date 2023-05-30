// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Created by ruslan515 on 30.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int answer = 0;
        int n = s.size();
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < k; ++i) {
            if (vowels.count(s[i])) {
                ++answer;
            }
        }

        int count = answer;
        for (int i = k; i < n; ++i) {
            char left = s[i - k];
            if (vowels.count(left)) {
                --count;
            }
            char right = s[i];
            if (vowels.count(right)) {
                ++count;
            }
            answer = max(answer, count);
        }


        return answer;

    }
};

int main() {
    string s;
    int k, answer;
    Solution solve;

    s = "abciiidef", k = 3;
    answer = 3;
    assert(solve.maxVowels(s, k) == answer);

    s = "aeiou", k = 2;
    answer = 2;
    assert(solve.maxVowels(s, k) == answer);

    s = "leetcode", k = 3;
    answer = 2;
    assert(solve.maxVowels(s, k) == answer);

    return 0;
}
