// https://leetcode.com/problems/count-of-matches-in-tournament/?envType=daily-question&envId=2023-12-05
// Created by omega515 on 05.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int answer = 0;
        while (n != 1) {
            if (n % 2 == 0){
                n /= 2;
                answer += n;
            } else {
                answer += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }

        return answer;
    }
};

int main() {
    int n, answer;
    Solution solve;

    n = 1;
    answer = 0;
    assert(answer == solve.numberOfMatches(n));

    n = 7;
    answer = 6;
    assert(answer == solve.numberOfMatches(n));

    n = 14;
    answer = 13;
    assert(answer == solve.numberOfMatches(n));

    return 0;
}