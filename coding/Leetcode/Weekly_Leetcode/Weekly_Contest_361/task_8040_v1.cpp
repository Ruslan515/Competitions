// https://leetcode.com/contest/weekly-contest-361/problems/minimum-operations-to-make-a-special-number/
// Created by ruslan515 on 03.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> st = {"00", "25", "50", "75"};
    int minimumOperations(string s) {
        int n = s.size();
        vector<int > ans;
        for (int i = n- 1; i >= 0; --i) {
            if (s[i] == '0') {
                bool ok = 0;
                for (int j = i -1; j >= 0; --j) {
                    if (s[j] == '0') {
                        ok = 1;
                        int cnt = n-1-i;
                        cnt += (i - j -1);
                        ans.push_back(cnt);
                        break;
                    }
                }
                if (ok) break;
            }
        }
        for (int i = n- 1; i >= 0; --i) {
            if (s[i] == '5') {
                bool ok = 0;
                for (int j = i -1; j >= 0; --j) {
                    if (s[j] == '2') {
                        ok = 1;
                        int cnt = n-1-i;
                        cnt += (i - j -1);
                        ans.push_back(cnt);
                        break;
                    }
                }
                if (ok) break;
            }
        }
        return 0;
    }
};

int main() {
    string num;
    int answer;
    Solution solve;

    num = "15";
    answer = 2;
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

    num = "10";
    answer = 1;
    assert(answer == solve.minimumOperations(num));

    num = "2245047";
    answer = 2;
    assert(answer == solve.minimumOperations(num));

    return 0;
}

