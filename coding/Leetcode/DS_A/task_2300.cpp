// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
// Created by omega515 on 20.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        vector<int> answer;
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        for (int i = 0; i < n; ++i) {
            int left = 0;
            int right = m - 1;
            int mid;
            int cur_spell = spells[i];
            int val;
            long long prod;
            while (left < right) {
                mid = left + (right - left) / 2;
                val = potions[mid];
                prod = (long long) val * cur_spell;
                if (prod >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int to = 0;
            if (left == (m - 1)) {
                val = potions[left];
                prod = (long long) val * cur_spell;
                if (prod >= success) {
                    to = 1;
                }
            } else {
                to = m - left;
            }

            answer.push_back(to);
        }

        return answer;
    }
};

int main() {
    vector<int> spells, potions;
    long long success;
    vector<int> answer;
    Solution solve;

    spells = {1, 2, 3, 4, 5, 6, 7}, potions = {1, 2, 3, 4, 5, 6, 7}, success = 25;
    answer = {0, 0, 0, 1, 3, 3, 4};
    assert(answer == solve.successfulPairs(spells, potions, success));

    spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5}, success = 7;
    answer = {4, 0, 3};
    assert(answer == solve.successfulPairs(spells, potions, success));

    spells = {3, 1, 2}, potions = {8, 5, 8}, success = 16;
    answer = {2, 0, 2};
    assert(answer == solve.successfulPairs(spells, potions, success));
    return 0;
}

