// https://leetcode.com/contest/weekly-contest-361/problems/minimum-operations-to-make-a-special-number/
// Created by ruslan515 on 03.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int answer = 0;
        if (num == "0" || num == "25" || num == "50" || num == "75") {
            return answer;
        } else if (num.size() == 1) {
            return 1;
        }
        int n = num.size();
        char temp;
        int i = n - 1;
        int n1, n2;
        // for 5
        int max5 = 0;
        for (; i >= 0; --i) {
            temp = num[i];
            if (temp == '5') {
                n1 = int(num[i]) - 48;
                --i;
                break;
            }
            ++max5;
        }
        bool flag5 = false;
        if (i >= 0) {
            for (; i >= 0; --i) {
                temp = num[i];
                if (temp == '2' || temp == '7') {
                    flag5 = true;
                    break;
                }
                ++max5;
            }
        }
//        if (!flag5) {
//            max5 = num.size();
//        }

        // for 0
        i = n - 1;
        int max0 = 0;

        for (; i >= 0; --i) {
            temp = num[i];
            if (temp == '0') {
                n1 = int(num[i]) - 48;
                --i;
                break;
            }
            ++max0;
        }
        bool  flag0 = false;
        if (i >= 0) {
            for (; i >= 0; --i) {
                temp = num[i];
                if (temp == '0' || temp == '5') {
                    flag0 = true;
                    break;
                }
                ++max0;
            }
        }
//        if (!flag0) {
//            max0= num.size();
//        }

        answer = min(max(max5, 0), max(max0, 0));
        return answer;
    }
};

int main() {
    string num;
    int answer;
    Solution solve;

    num = "15";
    answer = 2;
    assert(answer == solve.minimumOperations(num));

    num = "10";
    answer = 1;
    assert(answer == solve.minimumOperations(num));

    num = "1";
    answer = 1;
    assert(answer == solve.minimumOperations(num));

    num = "125";
    answer = 0;
    assert(answer == solve.minimumOperations(num));

    num = "0";
    answer = 0;
    assert(answer == solve.minimumOperations(num));

    num = "25";
    answer = 0;
    assert(answer == solve.minimumOperations(num));

    num = "2908305";
    answer = 3;
    assert(answer == solve.minimumOperations(num));

    num = "2245047";
    answer = 2;
    assert(answer == solve.minimumOperations(num));

    return 0;
}

