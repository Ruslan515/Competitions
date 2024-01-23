// https://leetcode.com/contest/weekly-contest-380/problems/find-beautiful-indices-in-the-given-array-ii/
// Created by omega515 on 14.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> answer;
        vector<int> positions_a, positions_b;
        int i = 0;
        int n = s.size();
        int lenA = a.size();
        int lenB = b.size();
        while (i < n) {
            if (s[i] == a[0]) {
                int startIdx = i;
                int j = 0;
                while (i < n && j < lenA && s[i] == a[j]) {
                    ++i;
                    ++j;
                }
                if (j == lenA) {
                    positions_a.push_back(startIdx);
                    --i;
                }
            }
            if (s[i] == b[0]) {
                int startIdx = i;
                int j = 0;
                while (i < n && j < lenB && s[i] == b[j]) {
                    ++i;
                    ++j;
                }
                if (j == lenB) {
                    positions_b.push_back(startIdx);
                    --i;
                }
            }
            ++i;
        }

        for (int pos_a: positions_a) {
            for (int pos_b: positions_b) {
                int diff = abs(pos_a - pos_b);
                if (diff <= k) {
                    answer.push_back(pos_a);
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    string s, a, b;
    int k;
    vector<int> answer;
    Solution solve;

    s = "lagopphhnl", a = "gopph", b = "hnl", k = 8;
    answer = {2};
    assert(answer == solve.beautifulIndices(s, a, b, k));

    s = "abcd", a = "a", b = "a", k = 4;
    answer = {0};
    assert(answer == solve.beautifulIndices(s, a, b, k));

    s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15;
    answer = {16, 33};
    assert(answer == solve.beautifulIndices(s, a, b, k));

    return 0;
}

