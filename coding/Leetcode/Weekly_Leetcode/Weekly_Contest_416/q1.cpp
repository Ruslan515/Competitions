// https://leetcode.com/contest/weekly-contest-416/problems/report-spam-message/description/
// Created by omega515 on 22.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> getSet(vector<string> &arr) {
        unordered_set<string> st;
        for (string s: arr) {
            st.insert(s);
        }
        return st;
    }

    bool reportSpam(vector<string> &message, vector<string> &bannedWords) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        unordered_set<string> stBanned = getSet(bannedWords);
        int cnt = 0;
        for (string s: message) {
            if (stBanned.find(s) != stBanned.end()) {
                ++cnt;
            }
            if (cnt == 2) {
                answer = true;
                break;
            }
        }


        return answer;
    }
};

int main() {
    vector<string> message, bannedWords;
    bool answer;
    Solution solve;

    message = {"l", "i", "l", "i", "l"}, bannedWords = {"d", "a", "i", "v", "a"};
    answer = true;
    assert(answer == solve.reportSpam(message, bannedWords));

    message = {"hello", "world", "leetcode"}, bannedWords = {"world", "hello"};
    answer = true;
    assert(answer == solve.reportSpam(message, bannedWords));

    message = {"hello", "programming", "fun"}, bannedWords = {"world", "programming", "leetcode"};
    answer = false;
    assert(answer == solve.reportSpam(message, bannedWords));

    return 0;
}
