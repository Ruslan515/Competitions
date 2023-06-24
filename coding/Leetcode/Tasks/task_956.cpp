// https://leetcode.com/problems/tallest-billboard/
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int> &rods) {
        int answer = 0;
        int sums = 0;
        for (auto num: rods) {
            sums += num;
        }
        int n = rods.size();
        if (sums & 1) {
            if (n == 2) {
                return answer;
            }
            sort(rods.begin(), rods.end());
            for (auto num: rods) {
                if (num & 1) {
                    sums -= num;
                    break;
                }
            }
            answer = sums / 2;

        } else {
            answer = sums / 2;
        }

        return answer;
    }
};

int main() {
    vector<int> rods;
    int answer;
    Solution solve;

    rods = {1, 2, 3, 6};
    answer = 6;
    assert(answer == solve.tallestBillboard(rods));

    rods = {1, 2, 3, 4, 5, 6};
    answer = 10;
    assert(answer == solve.tallestBillboard(rods));

    rods = {1, 2};
    answer = 0;
    assert(answer == solve.tallestBillboard(rods));

    return 0;
}