// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Created by ruslan515 on 22.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> answer;
        answer.push_back(first);
        int n = encoded.size() + 1;
        for (int i = 1; i < n; ++i) {
            int a = encoded[i - 1] ^ answer[i - 1];
            answer.push_back(a);
        }
        return answer;
    }
};

int main() {
    vector<int> encoded, answer;
    int first;
    Solution solve;

    encoded = {1, 2, 3};
    first = 1;
    answer = {1, 0, 2, 1};
    assert(solve.decode(encoded, first) == answer);

    encoded = {6, 2, 7, 3};
    first = 4;
    answer = {4, 2, 0, 7, 4};
    assert(solve.decode(encoded, first) == answer);

    return 0;
}