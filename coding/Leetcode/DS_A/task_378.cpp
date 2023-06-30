// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
// Created by ruslan515 on 30.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int answer = 0;
        priority_queue<int> pq;
        int el;
        int cnt = max(n, n - k);
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < cnt; ++j) {
                el = matrix[i][j];
                if (pq.size() == k) {
                    if (pq.top() > el) {
                        pq.pop();
                        pq.push(el);
                    }
                } else {
                    pq.push(el);
                }
            }
        }

        answer = pq.top();
        return answer;
    }
};

int main() {
    vector<vector<int>> matrix;
    int k;
    int answer;
    Solution solve;

    matrix = {{1,  5,  12},
              {6,  11, 13},
              {12, 13, 15}}, k = 3;
    answer = 6;
    assert(answer == solve.kthSmallest(matrix, k));

    matrix = {{-5}}, k = 1;
    answer = -5;
    assert(answer == solve.kthSmallest(matrix, k));

    return 0;
}
