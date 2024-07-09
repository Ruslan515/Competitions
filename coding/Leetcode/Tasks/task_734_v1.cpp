// https://leetcode.com/problems/sentence-similarity/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 02.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool
    areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        int n1 = sentence1.size(), n2 = sentence2.size();
        if (n1 != n2) {
            return answer;
        }

        unordered_map<string, set<string>> mp;
        for (auto pair: similarPairs) {
            string first = pair[0], second = pair[1];
            mp[first].insert(second);
            mp[second].insert(first);
        }
        string s1, s2, val;
        set<string> st;
        answer = true;
        for (int i = 0; i < n1; ++i) {
            s1 = sentence1[i];
            s2 = sentence2[i];
            if (s1 != s2) {
                if (mp.count(s1) == 0) {
                    answer = false;
                    break;
                }
                st = mp[s1];
                if (st.count(s2) == 0) {
                    answer = false;
                    break;
                }
            }
        }


        return answer;
    }
};

int main() {
    vector<string> sentence1, sentence2;
    vector<vector<string>> similarPairs;
    int answer;
    Solution solve;

    sentence1 = {"an", "extraordinary", "meal"};
    sentence2 = {"one", "good", "dinner"};
    similarPairs = {{"great",         "good"},
                    {"extraordinary", "good"},
                    {"well",          "good"},
                    {"wonderful",     "good"},
                    {"excellent",     "good"},
                    {"fine",          "good"},
                    {"nice",          "good"},
                    {"any",           "one"},
                    {"some",          "one"},
                    {"unique",        "one"},
                    {"the",           "one"},
                    {"an",            "one"},
                    {"single",        "one"},
                    {"a",             "one"},
                    {"truck",         "car"},
                    {"wagon",         "car"},
                    {"automobile",    "car"},
                    {"auto",          "car"},
                    {"vehicle",       "car"},
                    {"entertain",     "have"},
                    {"drink",         "have"},
                    {"eat",           "have"},
                    {"take",          "have"},
                    {"fruits",        "meal"},
                    {"brunch",        "meal"},
                    {"breakfast",     "meal"},
                    {"food",          "meal"},
                    {"dinner",        "meal"},
                    {"super",         "meal"},
                    {"lunch",         "meal"},
                    {"possess",       "own"},
                    {"keep",          "own"},
                    {"have",          "own"},
                    {"extremely",     "very"},
                    {"actually",      "very"},
                    {"really",        "very"},
                    {"super",         "very"}};
    answer = true;
    assert(answer == solve.areSentencesSimilar(sentence1, sentence2, similarPairs));

    sentence1 = {"great", "acting", "skills"}, sentence2 = {"fine", "drama",
                                                            "talent"}, similarPairs = {{"great",  "fine"},
                                                                                       {"drama",  "acting"},
                                                                                       {"skills", "talent"}};
    answer = true;
    assert(answer == solve.areSentencesSimilar(sentence1, sentence2, similarPairs));

    sentence1 = {"great"}, sentence2 = {"great"}, similarPairs = {};
    answer = true;
    assert(answer == solve.areSentencesSimilar(sentence1, sentence2, similarPairs));

    sentence1 = {"great"}, sentence2 = {"doubleplus", "good"}, similarPairs = {{"great", "doubleplus"}};
    answer = false;
    assert(answer == solve.areSentencesSimilar(sentence1, sentence2, similarPairs));

    return 0;
}
