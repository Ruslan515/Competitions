// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
// Created by ruslan515 on 08.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int n, int m) {
        if (m == 0) {
            return n;
        } else {
            return gcd(m, n % m);
        }
    }

    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        if (str1 + str2 != str2 + str1) {
            return ans;
        }

        int gcd_len = gcd(str1.size(), str2.size());
        ans = str1.substr(0, gcd_len);

        return ans;
    }
};

void read_data(string &str1, string &str2) {
    cin >> str1 >> str2;
    return;
}

int main() {
    string str1;
    string str2;
    read_data(str1, str2);
    Solution solve;
    cout << solve.gcdOfStrings(str1, str2);

    return 0;
}