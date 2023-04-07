// https://leetcode.com/problems/reverse-string/description/
// Created by ruslan515 on 07.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int n = s.size();
        char temp;
        for (int i = 0; i < n / 2; ++i) {
            temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }

    }
};

int main() {
    vector<char> s;

    Solution solve;
    s = {'h', 'e', 'l', 'l', 'o'};
    solve.reverseString(s);
    for (auto c: s) {
        cout << c << " ";
    }
    cout << "\n";

    return 0;
}