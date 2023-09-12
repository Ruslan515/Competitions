// https://leetcode.com/contest/weekly-contest-361/problems/count-symmetric-integers/
// Created by ruslan515 on 03.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(int x) {
        bool answer = false;
        vector<int> v;
        int d;
        while (x != 0) {
            d = x % 10;
            v.push_back(d);
            x /= 10;
        }
        int n = v.size();
        if (n % 2 == 0) {
            int s1 = 0, s2 = 0;
            for (int i = 0; i < n / 2; ++i) {
                s1 += v[i];
                s2 += v[n - i - 1];
            }
            if (s1 == s2) {
                answer = true;
            }
        }

        return answer;
    }

    int countSymmetricIntegers(int low, int high) {
        int answer = 0;
        for (int x = low; x <= high; ++x) {
            bool ch = check(x);
            if (ch) {
                ++answer;
            }
        }

        return answer;
    }
};

int main() {
    int low;
    int high;
    int answer;
    Solution solve;

    low = 1, high = 100;
    answer = 9;
    assert(answer == solve.countSymmetricIntegers(low, high));

    low = 1200, high = 1230;
    answer = 4;
    assert(answer == solve.countSymmetricIntegers(low, high));

    return 0;
}

