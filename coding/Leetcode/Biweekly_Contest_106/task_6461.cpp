// https://leetcode.com/contest/biweekly-contest-106/problems/check-if-the-number-is-fascinating/
// Created by Ruslan Khalikov on 10.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void getNumbs(map<int, int> &mp, int x) {
        int v = 10;
        while (x != 0) {
            int d = x % v;
            ++mp[d];
            x /= v;
        }
    }

    bool isFascinating(int n) {
        int n2 = 2 * n;
        int n3 = 3 * n;
        map<int, int> mp;
        getNumbs(mp, n);
        getNumbs(mp, n2);
        getNumbs(mp, n3);

        bool answer = true;
        if (mp.count(0)) {
            answer = false;
        } else {
            for (int i = 1; i < 10; ++i) {
                if (mp[i] != 1) {
                    answer = false;
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {
    int n;
    bool answer;
    Solution solve;

    n = 783;
    answer = false;
    assert(answer == solve.isFascinating(n));

    n = 192;
    answer = true;
    assert(answer == solve.isFascinating(n));

    n = 100;
    answer = false;
    assert(answer == solve.isFascinating(n));

    return 0;
}

