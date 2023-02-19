// https://leetcode.com/contest/weekly-contest-333/problems/merge-two-2d-arrays-by-summing-values/
// Created by ruslan515 on 19.02.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans;
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            int id1 = nums1[i1][0];
            int id2  = nums2[i2][0];
            int val_ans = 0;
            int id_ans = 0;
            if (id1 == id2) {
                val_ans = nums1[i1][1] + nums2[i2][1];
                id_ans = id1;
                ++i1;
                ++i2;
            } else if (id1 < id2) {
                val_ans = nums1[i1][1];
                id_ans = id1;
                ++i1;
            } else {
                val_ans = nums2[i2][1];
                id_ans = id2;
                ++i2;
            }
            vector<int> temp;
            temp.push_back(id_ans);
            temp.push_back(val_ans);
            ans.push_back(temp);
        }
        if (i1 < n1) {
            for (; i1 < n1; ++i1) {
                ans.push_back(nums1[i1]);
            }
        } else if (i2 < n2) {
            for (; i2 < n2; ++i2) {
                ans.push_back(nums2[i2]);
            }

        }

        return ans;
    }
};


void read_data(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        cin >> a >> b;
        t.push_back(a);
        t.push_back(b);
        nums1.push_back(t);
    }

    for (int i = 0; i < m; ++i) {
        vector<int> t;
        cin >> a >> b;
        t.push_back(a);
        t.push_back(b);
        nums2.push_back(t);
    }

    return;
}

int main() {
    vector<vector<int>> nums1;
    vector<vector<int>> nums2;
    read_data(nums1, nums2);
    Solution solve;
    vector<vector<int>> ans = solve.mergeArrays(nums1, nums2);
    for (int i = 0; i < ans.size(); ++i) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "], ";
    }
    cout << "\n";

    return 0;
}