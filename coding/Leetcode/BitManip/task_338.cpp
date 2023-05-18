// https://leetcode.com/problems/counting-bits/description/
// Created by ruslan515 on 18.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        answer.push_back(0);
        for (int i = 1; i < n + 1; ++i) {
            int count = 0;
            int x = i;
            int mask = 1;
            while (x != 0) {
                int y = x & mask;
                if (y == 1) {
                    ++count;
                }
                x >>= 1;
            }
            answer.push_back(count);
        }
        return answer;

    }
};

int main() {
    vector<int> answer;
    int n;
    Solution solve;

    n = 2;
    answer = {0,1,1};
    assert(solve.countBits(n) == answer);

    n = 5;
    answer = {0,1,1,2,1,2};
    assert(solve.countBits(n) == answer);

    return 0;
}