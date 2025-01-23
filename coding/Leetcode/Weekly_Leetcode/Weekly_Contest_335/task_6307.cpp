// https://leetcode.com/contest/weekly-contest-335/problems/pass-the-pillow/
// Created by ruslan515 on 05.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int ans;
        int x = n - 1;
        int d = time / x;
        if (d % 2 == 0) {
            int t = time - d * x;
            ans = 1 + t;
        } else {
            int t = time - d * x;
            ans = n - t;
        }

        return ans;
    }
};


void read_data(int n, int time) {
    cin >> n >> time;
    return;
}

int main() {
    int n;
    int time;
    read_data(n, time);
    Solution solve;
//    assert(solve.passThePillow(18, 38) == 5);

    assert(solve.passThePillow(4, 5) == 2);
    assert(solve.passThePillow(3, 2) == 3);


    return 0;
}