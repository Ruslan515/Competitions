// https://leetcode.com/problems/sentence-similarity/
// Created by ruslan515 on 21.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(
            vector<string>& sentence1,
            vector<string>& sentence2,
            vector<vector<string>>& similarPairs
            ) {
        bool ans = true;
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        if (n1 != n2) {
            ans = false;
        } else {
            map<string, set<string>> mp1;
            map<string, set<string>> mp2;
            int m = similarPairs.size();
            string key, value;
            for (int i = 0; i < m; ++i) {
                key = similarPairs[i][0];
                value = similarPairs[i][1];
                mp1[key].insert(value);
                mp2[value].insert(key);
            }

            string key1, key2;
            set<string> val1, val2;

            for (int i = 0; i < n1; ++i) {
                key1 = sentence1[i];
                key2 = sentence2[i];
                val1 = mp1[key1];
                val2 = mp2[key1];
                bool a = key1 == key2;
                bool b = true;
                if (val1.find(key2) == val1.end()) {
                    b = false;
                }
//                bool b = val1 == key2;
                bool c = true;
                if (val2.find(key2) == val2.end()) {
                    c = false;
                }
//                bool c = val2 == key2;

                if (!(a || b || c)) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};

void read_data(
        vector<string>& sentence1,
        vector<string>& sentence2,
        vector<vector<string>>& similarPairs
        ) {
    int n;
    string temp;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        sentence1.push_back(temp);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        sentence2.push_back(temp);
    }

    cin >> n;
    string temp1;
    for (int i = 0; i < n; ++i) {
        cin >> temp >> temp1;
        similarPairs.push_back({temp, temp1});
    }


    return;
}

int main() {
    vector<string> sentence1;
    vector<string> sentence2;
    vector<vector<string>> similarPairs;

    read_data(sentence1, sentence2, similarPairs);
    Solution solve;
    cout << solve.areSentencesSimilar(sentence1, sentence2, similarPairs);

    return 0;
}