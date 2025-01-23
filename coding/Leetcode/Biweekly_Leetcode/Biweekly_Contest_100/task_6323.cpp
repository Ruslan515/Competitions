// https://leetcode.com/contest/biweekly-contest-100/problems/distribute-money-to-maximum-children/
// Created by ruslan515 on 18.03.23.
//

#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int distMoney(int money, int children) {
//        int ans = -1;
//        if (money < children) {
//            return ans;
//        }
//        if (money == 8) {
//            return 0;
//        }
//        if (money % 8 == 0 && money / 8 >= children) {
//            ans = money / 8;
//        } else {
//            while (money != 0) {
//                ans = money / 8;
//                int d = money % 8;
//                int x = children - ans;
//                if (d > x && x != 1) {
//                    return ans;
//                }
//                else if (d == 4 && x == 1) {
//                    money -= 8;
//                    ans = money / 8;
//                    d = money % 8;
//                }
//                else {
//                    int t = children - ans;
//                    if (d >= t) {
//                        return ans;
//                    } else {
//                        money -= 8;
//                        ans = money / 8;
//                        d = money % 8;
//                    }
//                }
////                money -= ans * 8 + d;
//
//            }
//
//        }
//        return ans;
//    }
//};

class Solution {
public:
    int distMoney(int money, int children) {
        int ans = -1;
        if (children > money)
            return ans;
        if (money < 8)
            return 0;
        int d = money / 8;
        int mod = money % 8;
        if (d == children && mod == 0)
            return children;
        if (d >= children)
            return children - 1;

        if (mod == 4 && (children - d) == 1)
            return children - 2;

        if (mod >= (children - d))
            return d;

        int left = children - d;
        while (mod < left) {
            left++;
            mod += 8;
            d--;
        }

        return d;
    }
};

int main() {
    Solution solve;
    assert(solve.distMoney(20, 3) == 1);
    assert(solve.distMoney(16, 2) == 2);
    assert(solve.distMoney(1, 2) == -1);
    assert(solve.distMoney(2, 2) == 0);
    assert(solve.distMoney(8, 2) == 0);
    assert(solve.distMoney(12, 3) == 1);
    assert(solve.distMoney(16, 3) == 1);
    assert(solve.distMoney(16, 10) == 0);

    return 0;
}