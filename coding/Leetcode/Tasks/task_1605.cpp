// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20
// Created by omega515 on 20.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int nr = rowSum.size(), nc = colSum.size();
        vector<vector<int>> answer(nr, vector<int>(nc, 0));
        int prev, prevIdx;
        if (rowSum[0] < colSum[0]) {
            answer[0][0] = rowSum[0];
            for (int i = 1; i < min(nr, nc); ++i) {
                prevIdx = i - 1;
                prev = colSum[prevIdx] - answer[prevIdx][prevIdx];
                answer[i][prevIdx] = prev;
                answer[i][i] = rowSum[i] - prev;
            }
        } else {
            answer[0][0] = colSum[0];
            for (int j = 1; j < min(nc, nr); ++j) {
                prevIdx = j - 1;
                prev = rowSum[prevIdx] - answer[prevIdx][prevIdx];
                answer[prevIdx][j] = prev;
                answer[j][j] = colSum[j] - prev;
            }
            int x, y;
            int idx;
            if (nc > nr & nr != 1) {
                idx = nr - 1;
                x = rowSum[idx];
                y = answer[idx][idx];
                answer[idx][nr] = x - y;
            } else if (nr > nc & nc != 1) {
                idx = nc - 1;
                x = colSum[idx];
                y = answer[idx][idx];
                answer[idx][idx] = x - y;
            }

        }

        return answer;
    }
};


int main() {
    vector<int> rowSum, colSum;
    vector<vector<int>> answer;
    Solution solve;

    rowSum = {4, 12, 10, 1, 0}, colSum = {1, 0, 3, 16, 7};
    answer = {{0, 0, 3, 0,  1},
              {0, 0, 0, 12, 0},
              {0, 0, 0, 4,  6},
              {1, 0, 0, 0,  0},
              {0, 0, 0, 0,  0}};
    assert(answer == solve.restoreMatrix(rowSum, colSum));

    rowSum = {1, 0}, colSum = {1};
    answer = {{1},
              {0}};
    assert(answer == solve.restoreMatrix(rowSum, colSum));

    rowSum = {14, 9}, colSum = {6, 9, 8};
    answer = {{6, 8, 0},
              {0, 1, 8}};
    assert(answer == solve.restoreMatrix(rowSum, colSum));

    rowSum = {3, 8}, colSum = {4, 7};
    answer = {
            {3, 0},
            {1, 7}
    };
    assert(answer == solve.restoreMatrix(rowSum, colSum));

    rowSum = {5, 7, 10}, colSum = {8, 6, 8};
    answer = {{5, 0, 0},
              {3, 4, 0},
              {0, 2, 8}};
    assert(answer == solve.restoreMatrix(rowSum, colSum));
    return 0;
}