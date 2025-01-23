// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10
// Created by omega515 on 10.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        int n = s.size();
        unordered_map<string, int> uniqueStringDict;
        unordered_map<char, int> uniqueCharDict;
        int left = 0, right = 0;
        char ch;
        while (left < n && left <= right) {
            ch = s[right];
            while (right < n && s[right] == ch) {
                ++right;
            }
            int cnt = right - left;
            uniqueCharDict[ch] += cnt;

            string tmp = "";
            for (int i = 0; i < cnt; ++i) {
                tmp += ch;
            }
            ++uniqueStringDict[tmp];
            left = right;
        }

        if (uniqueStringDict.size() == 1) {
            answer = n - 2;
        } else {
            int tmp;
            for (auto it = uniqueStringDict.begin(); it != uniqueStringDict.end();) {
                if (it->second < 3) {
                    string x = it->first;
                    if (x.size() == 1){
                        char ch = x[0];
                        tmp = uniqueCharDict[ch];
                        if (tmp >= 3) {
                            answer = max(answer, 1);
                        }
                    } else {
                        tmp = it->first.size();
                        if (tmp >= 3) {
                            answer = max(answer, tmp - 2);
                        }
                    }
                    it = uniqueStringDict.erase(it);

                } else {
                    tmp = it->first.size();
                    answer = max(answer, tmp);
                    ++it;
                }
            }

        }


        return answer;
    }
};


int main() {
    string s;
    int answer;
    Solution solve;

    s = "eccdnmcnkl";
    answer = 1;
    assert(answer == solve.maximumLength(s));

    s = "cbc";
    answer = -1;
    assert(answer == solve.maximumLength(s));

    s = "abcaba";
    answer = 1;
    assert(answer == solve.maximumLength(s));

    s = "abcccccdddd";
    answer = 3;
    assert(answer == solve.maximumLength(s));

    s = "aaaa";
    answer = 2;
    assert(answer == solve.maximumLength(s));

    s = "abcdef";
    answer = -1;
    assert(answer == solve.maximumLength(s));

    return 0;
}
