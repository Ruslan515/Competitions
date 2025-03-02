// https://leetcode.com/contest/weekly-contest-437/problems/find-special-substring-of-length-k/?slug=eat-pizzas&tab=description&region=global_v2
// Created by omega515 on 16.02.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        int n = s.size();
        for (int i = 0; i < n - k + 1; ++i) {
            set<char> setCh;
            for (int j = 0; j < k; ++j) {
                setCh.insert(s[i + j]);
            }
            if (setCh.size() == 1) {
                int leftIdx = i - 1;
                if (leftIdx >= 0) {
                    char left = s[leftIdx];
                    if (setCh.find(left) != setCh.end()) {
                        continue;
                    }
                }
                int rightIdx = i + k;
                if (rightIdx < n) {
                    char right = s[rightIdx];
                    if (setCh.find(right) != setCh.end()) {
                        continue;
                    }
                }
                answer = true;
                break;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    int k;
    bool answer;
    Solution solve;

    s = "aaaaaaabaaa", k = 3;
    answer = true;
    assert(answer == solve.hasSpecialSubstring(s, k));

    s = "aaaaaaa", k = 3;
    answer = false;
    assert(answer == solve.hasSpecialSubstring(s, k));

    s = "aaabaaa", k = 3;
    answer = true;
    assert(answer == solve.hasSpecialSubstring(s, k));

    s = "abc", k = 2;
    answer = false;
    assert(answer == solve.hasSpecialSubstring(s, k));

    return 0;
}
