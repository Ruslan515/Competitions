// https://leetcode.com/problems/longest-repeating-substring/description/?envType=weekly-question&envId=2024-08-01
// Created by omega515 on 06.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
//        unordered_map<string, int> mp;
        unordered_set<long long> unique, notUnique;
        int n = s.size();
        string sub;
        int size;
        hash<string> hasher;
        for (int len = n - 1; len > 0; --len) {
            for (int start = 0; start < n - len + 1; ++start) {
                sub = s.substr(start, len);
                long long hash = hasher(sub);
                if (unique.find(hash) != unique.end()) {
                    unique.erase(hash);
                    notUnique.insert(hash);
                    size = sub.size();
                    if (size > answer) {
                        answer = size;
                        break;
                    }
                } else if (notUnique.find(hash) == notUnique.end()) {
                    unique.insert(hash);
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

    s = "aaaaa";
    answer = 4;
    assert(answer == solve.longestRepeatingSubstring(s));

    s = "abbaba";
    answer = 2;
    assert(answer == solve.longestRepeatingSubstring(s));

    s = "aabcaabdaab";
    answer = 3;
    assert(answer == solve.longestRepeatingSubstring(s));

    s = "abcd";
    answer = 0;
    assert(answer == solve.longestRepeatingSubstring(s));

    return 0;
}
