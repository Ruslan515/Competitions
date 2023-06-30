// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
// Created by ruslan515 on 29.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        map<int, vector<int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m ; ++i) {
            vector<int> row = mat[i];
            int countOnes = 0;
            while (countOnes < n && row[countOnes] == 1) {
                ++countOnes;
            }
            mp[countOnes].push_back(i);
        }
        vector<int> answer;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto el: mp) {
            int count = el.first;
            vector<int> temp = el.second;
            for (auto t: temp) {
                pq.push({count, t});
            }
        }
        pair<int, int> x;
        int size_pq = pq.size();
        int count = min(k, size_pq);
        for(int i = 0; i < count; ++i) {
            x = pq.top();
            pq.pop();
            answer.push_back(x.second);
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> mat;
    int k;
    vector<int> answer;
    Solution solve;

    mat = {{1, 1, 0, 0, 0},
           {1, 1, 1, 1, 0},
           {1, 0, 0, 0, 0},
           {1, 1, 0, 0, 0},
           {1, 1, 1, 1, 1}};
    k = 3;
    answer = {2, 0, 3};
    assert(answer == solve.kWeakestRows(mat, k));

    mat = {{1, 0, 0, 0},
           {1, 1, 1, 1},
           {1, 0, 0, 0},
           {1, 0, 0, 0}};
    k = 2;
    answer = {0, 2};
    assert(answer == solve.kWeakestRows(mat, k));

    return 0;
}
