// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23
// Created by omega515 on 23.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLength(vector<string> &arr) {
        // Initialize results with an empty string
        // from which to build all future results
        vector<string> results = {""};
        int best = 0;
        for (string word: arr) {
            // We only want to iterate through results
            // that existed prior to this loop
            int resultsLen = results.size();
            for (int i = 0; i < resultsLen; i++) {
                // Form a new result combination and
                // use a set to check for duplicate characters
                string newRes = results[i] + word;
                unordered_set<char> newResSet(newRes.begin(), newRes.end());
                if (newRes.size() != newResSet.size())
                    continue;

                // Add valid options to results and
                // keep track of the longest so far
                results.push_back(newRes);
                best = max(best, (int) newRes.size());
            }
        }
        return best;
    }
};

int main() {
    vector<string> arr;
    int answer;

    Solution solve;

    arr = {"un", "iq", "ue"};
    answer = 4;
    assert(answer == solve.maxLength(arr));

    arr = {"cha", "r", "act", "ers"};
    answer = 6;
    assert(answer == solve.maxLength(arr));

    arr = {"abcdefghijklmnopqrstuvwxyz"};
    answer = 26;
    assert(answer == solve.maxLength(arr));

    return 0;
}