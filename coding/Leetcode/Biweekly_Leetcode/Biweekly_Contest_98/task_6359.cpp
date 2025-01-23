// https://leetcode.com/contest/biweekly-contest-98/problems/maximum-difference-by-remapping-a-digit/
// Created by ruslan515 on 18.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string n1 = to_string(num);
        string n2 = to_string(num);
        char c = n1[0];
        char ch = n1[0];
        for (int i = 0; i < n1.size(); ++i) {
            if (n1[i] != '9') {
                c = n1[i];
                break;
            }
        }
        for (int i = 0; i < n1.size(); ++i) {
            if (n1[i] == c) {
                n1[i] = '9';
            }
        }
        for(int i = 0; i < n1.size(); ++i) {
            if (n2[i] == ch) {
                n2[i] = '0';
            }
        }
        int max_n = stoi(n1);
        int min_n = stoi(n2);
        int ans = max_n - min_n;
        return ans;
    }
};
//class Solution {
//public:
//    int minMaxDifference(int num) {
//        vector<int> digits, copy_d;
//        int copy_num = num;
//        int first_digit;
//
//        while (copy_num != 0) {
//            int d = copy_num % 10;
//            digits.push_back(d);
//            copy_d.push_back(d);
//            copy_num /= 10;
//        }
//
//        reverse(digits.begin(), digits.end());
//        first_digit = digits[0];
//        int n = digits.size();
//
//        int i = 0;
//        while (digits[i] == 9) {
//            ++i;
//        }
//
//        if (i == n) {
//            int ans = 0;
//            int t = 1;
//            for (i = 0; i < n; i++) {
//                ans += 9 * t;
//                t *= 10;
//            }
//            return ans;
//        }
//
//        int digit_change = digits[i];
//        int max_ans = 0;
//        int min_ans = 0;
//        int t = 1;
//        for (i = n - 1; i >= 0; --i) {
//            int d = digits[i];
//
//            if (digits[i] == digit_change) {
//                d = 9;
//                max_ans += d * t;
//            } else {
//                max_ans += digits[i] * t;
//            }
//
//            if (digits[i] == first_digit) {
//                d = 0;
//                min_ans += d * t;
//            } else {
//                min_ans += digits[i] * t;
//            }
//
//            t *= 10;
//        }
//        int ans = max_ans - min_ans;
//        return ans;
//
//    }
//};

void read_data(int &num) {
    cin >> num;
    return;
}

int main() {
    int num;
    read_data(num);
    Solution solve;
    cout << solve.minMaxDifference(num);
    return 0;
}