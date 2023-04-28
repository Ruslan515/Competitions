// https://leetcode.com/problems/happy-number/
// Created by ruslan515 on 18.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        bool answer = false;
        unordered_map<int, int> mp;
        mp.insert({n, 1});
        while (true) {
            int sum = 0;
            while (n != 0) {
                int d = n % 10;
                sum += d * d;
                n /= 10;
            }
            if (sum == 1) {
                answer = true;
                break;
            } else {
                if (mp.count(sum)) {
                    break;
                } else {
                    mp.insert({sum, 0});
                }
            }
            n = sum;
        }
        return answer;
    }
};

int main() {
    int n;
    bool answer;
    Solution solve;

    n = 19;
    answer = true;
    assert(solve.isHappy(n) == answer);

    n = 2;
    answer = false;
    assert(solve.isHappy(n) == answer);

    return 0;
}