// https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
// Created by omega515 on 12.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>> &v, vector<int> &current, int n, int k) {
        int size = current.size();
        if (size == n) {
            v.push_back(current);
            return;
        }
        int prev = current[size - 1];
        int next;
        for (int t = -k; t <= k; t += 2 * k) {
            next = prev + t;
            if (next >= 0 && next <= 9) {
                current.push_back(next);
                backtracking(v, current, n, k);
                current.pop_back();
            }
        }

    }

    int convert(vector<int> current) {
        int answer = 0;
        int size = current.size();
        int d = 1;
        int t = 10;
        for (int i = size - 1; i >= 0; --i) {
            answer += current[i] * d;
            d *= t;
        }

        return answer;
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> answer;
        vector<vector<int>> v;
        if (k == 0) {
            for (int i = 1; i <= 9; ++i) {
                vector<int> current;
                for (int j = 0; j < n; ++j) {
                    current.push_back(i);
                }
                v.push_back(current);
            }
        } else {
            for (int i = 1; i <= 9; ++i) {
                vector<int> current = {i};
                backtracking(v, current, n, k);
            }
        }


        for (vector<int> current: v) {
            answer.push_back(convert(current));
        }

        return answer;
    }
};

int main() {
    int n, k;
    vector<int> answer;
    Solution solve;

    n = 2, k = 0;
    answer = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    assert(answer == solve.numsSameConsecDiff(n, k));

    n = 3, k = 7;
    answer = {181, 292, 707, 818, 929};
    assert(answer == solve.numsSameConsecDiff(n, k));

    n = 2, k = 1;
    answer = {10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98};
    assert(answer == solve.numsSameConsecDiff(n, k));

    return 0;
}
