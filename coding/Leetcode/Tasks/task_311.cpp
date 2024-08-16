// https://leetcode.com/problems/sparse-matrix-multiplication/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 19.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<int> intersect(unordered_set<int> st1, unordered_set<int> st2) {
        int n1 = st1.size();
        int n2 = st2.size();
        if (n1 > n2) {
            return intersect(st2, st2);
        }
        unordered_set<int> answer;
        for (const auto &num: st1) {
            if (st2.find(num) != st2.end()) {
                answer.insert(num);
            }
        }
        return answer;
    }

    vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = mat1.size(), k = mat2.size(), n = mat2[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));
        unordered_map<int, unordered_set<int>> cols, rows;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                if (mat1[i][j]) {
                    rows[i].insert(j);
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < k; ++i) {
                if (mat2[i][j]) {
                    cols[j].insert(i);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                unordered_set<int> col = cols[j];
                unordered_set<int> row = rows[i];
                unordered_set<int> inter = intersect(col, row);
                int sums = 0;
                for (const auto &idx: inter) {
                    sums += mat1[i][idx] * mat2[idx][j];
                }
                answer[i][j] = sums;
            }
        }

        return answer;
    }
};


int main() {
    vector<vector<int>> mat1, mat2, answer;
    Solution solve;

    mat1 = {{1,  0, 0},
            {-1, 0, 3}}, mat2 = {{7, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 1}};
    answer = {{7,  0, 0},
              {-7, 0, 3}};
    assert(answer == solve.multiply(mat1, mat2));

    mat1 = {{0}}, mat2 = {{0}};
    answer = {{0}};
    assert(answer == solve.multiply(mat1, mat2));

    return 0;
}