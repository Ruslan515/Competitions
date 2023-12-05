// https://leetcode.com/contest/weekly-contest-373/problems/matrix-similarity-after-cyclic-shifts/
// Created by ruslan515 on 26.11.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shift_r(vector<int> &v, int k) {
        int n = v.size();
        vector<int> answer(n, 0);
        int newIdx;
        for (int i = 0; i < n; ++i) {
            newIdx = (i + k) % n;
            answer[newIdx] = v[i];
        }

        return answer;
    }

    vector<int> shift_l(vector<int> &v, int k) {
        int n = v.size();
        vector<int> answer(n, 0);
        int newIdx;
        for (int i = 0; i < n; ++i) {
            newIdx = (n + i + k) % n;
            answer[newIdx] = v[i];
        }

        return answer;
    }

    bool areSimilar(vector<vector<int>> &mat, int k) {
        bool answer = true;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> shift;
            if (i % 2 == 0) {
                shift = shift_r(mat[i], k);
            } else {
                shift = shift_l(mat[i], k);
            }
            if (shift != mat[i]) {
                answer = false;
                break;
            }

        }

        return answer;
    }
};

int main() {
    vector<vector<int>> mat;
    int k;
    bool answer;
    Solution solve;

    mat = {{1, 2, 1, 2},
           {5, 5, 5, 5},
           {6, 3, 6, 3}}, k = 2;
    answer = true;
    assert(answer == solve.areSimilar(mat, k));

    mat = {{2, 2},
           {2, 2}}, k = 3;
    answer = true;
    assert(answer == solve.areSimilar(mat, k));

    mat = {{1, 2}}, k = 1;
    answer = false;
    assert(answer == solve.areSimilar(mat, k));

    return 0;
}

