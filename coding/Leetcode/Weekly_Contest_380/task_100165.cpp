// https://leetcode.com/contest/weekly-contest-380/problems/find-beautiful-indices-in-the-given-array-i/
// Created by omega515 on 14.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findPositions(string s, string x) {
        vector<int> positions;
        int pos = s.find(x, 0);
        while (pos != string::npos) {
            positions.push_back(pos);
            pos = s.find(x, pos + 1);
        }
        return positions;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> answer;
        vector<int> positions_a = findPositions(s, a), positions_b = findPositions(s, b);

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

    s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15;
    answer = {16, 33};
    assert(answer == solve.beautifulIndices(s, a, b, k));

    s = "abcd", a = "a", b = "a", k = 4;
    answer = {0};
    assert(answer == solve.beautifulIndices(s, a, b, k));


    return 0;
}

