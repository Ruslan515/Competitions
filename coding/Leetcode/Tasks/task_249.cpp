// https://leetcode.com/problems/group-shifted-strings/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 15.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string> &strings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<string>> answer;
        map<set<int>, vector<string>> mp;

        for (string s: strings) {
            int n = s.size();
            int diff, curr, next;
            set<int> st;
            for (int i = 0; i < n - 1; ++i) {
                diff = 0;
                curr = (int) s[i] - 87;
                next = (int) s[i + 1] - 87;
                if (next < curr) {
                    diff += (int) 'z' - 87 - next;
                    diff += curr - (int) 'a';
                } else {
                    diff = next - curr;
                }
                st.insert(diff);
            }
            next = (int) s[0] - 87;
            curr = (int) s[n - 1] - 87;
            diff = 0;
            if (next < curr) {
                diff += (int) 'z' - 87 - next;
                int x = curr - (int) 'a' - 87;
                diff += x;
            } else {
                diff = next - curr;
            }
            st.insert(diff);
            st.insert(diff);
            mp[st].push_back(s);
        }


        return answer;
    }
};

int main() {
    vector<string> strings;
    vector<vector<string>> answer;
    Solution solve;

    strings = {"az", "ba", "abc", "bcd", "acef", "xyz", "a", "z"};
    answer = {{"acef"},
              {"a",   "z"},
              {"abc", "bcd", "xyz"},
              {"az",  "ba"}};
    assert(answer == solve.groupStrings(strings));

    strings = {"a"};
    answer = {{"a"}};
    assert(answer == solve.groupStrings(strings));

    return 0;
}
