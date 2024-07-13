// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 10.07.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void intersect_set(vector<vector<int>> &mat, int idx, unordered_set<int> &res) {
        unordered_set<int> st1, st2;
        int n = mat[0].size();
        for (int i = 0; i < n; ++i) {
            st1.insert(mat[idx][i]);
            st2.insert(mat[idx + 1][i]);
        }

        for (int num: st1) {
            if (st2.find(num) != st2.end()) {
                res.insert(num);
            }
        }
    }

    int smallestCommonElement(vector<vector<int>> &mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        int m = mat.size();
        if (m == 1) {
            return mat[0][0];
        }
        int n = mat[0].size();
        unordered_set<int> res;
        intersect_set(mat, 0, res);

        if (res.empty()) {
            return answer;
        }
        for (int i = 2; i < m; ++i) {
            unordered_set<int> st;
            for (int j = 0; j < n; ++j) {
                st.insert(mat[i][j]);
            }
            unordered_set<int>::iterator it = res.begin();
            for (; it != res.end();) {
                if (res.empty()) {
                    return answer;
                }
                int num = *it;
                if (st.find(num) == st.end()) {
                    res.erase(it++);
                } else {
                    ++it;
                }
            }
            if (res.empty()) {
                return answer;
            }
        }

        vector<int> v;
        for (int num: res) {
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        answer = v[0];

        return answer;
    }
};

int main() {
    vector<vector<int>> mat;
    int answer;
    Solution solve;

    mat = {{1, 2, 3, 4, 5},
           {2, 4, 5, 8, 10},
           {3, 5, 7, 9, 11},
           {1, 3, 5, 7, 9}};
    answer = 5;
    assert(answer == solve.smallestCommonElement(mat));

    mat = {{1, 2, 3},
           {2, 3, 4},
           {2, 3, 5}};
    answer = 2;
    assert(answer == solve.smallestCommonElement(mat));

    return 0;
}
