// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04
// Created by omega515 on 04.03.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        int d;
        while (n != 0) {
            d = n % 3;
            if (d == 2) {
                return answer;
            }
            n /= 3;

        }
        answer = true;
        return answer;
    }
};

int main() {
    int n;
    bool answer;
    Solution solve;

    n = 21;
    answer = false;
    assert(answer == solve.checkPowersOfThree(n));

    n = 12;
    answer = true;
    assert(answer == solve.checkPowersOfThree(n));

    n = 91;
    answer = true;
    assert(answer == solve.checkPowersOfThree(n));

    return 0;
}

