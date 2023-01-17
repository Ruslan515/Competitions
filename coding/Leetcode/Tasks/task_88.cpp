// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 18.01.23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, idx_write = m + n - 1;
        while (idx1 >= 0 && idx2 >= 0) {
            int num1 = nums1[idx1];
            int num2 = nums2[idx2];
            int max_num;
            if (num1 > num2) {
                max_num = num1;
                --idx1;
            } else {
                max_num = num2;
                --idx2;
            }
            nums1[idx_write--] = max_num;
        }

        if (idx1 <= 0) {
            while (idx2 >= 0) {
                nums1[idx_write--] = nums2[idx2--];
            }
        } else {
            while (idx1 >= 0) {
                nums1[idx_write--] = nums1[idx1--];
            }
        }

        return;
    }

//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int idx1 = 0, idx2 = 0;
//        vector<int> ans;
//        while (idx1 < m && idx2 < n) {
//            int num1 = nums1[idx1];
//            int num2 = nums2[idx2];
//            int min_num;
//            if (num1 < num2) {
//                min_num = num1;
//                ++idx1;
//            } else {
//                min_num = num2;
//                ++idx2;
//            }
//            ans.push_back(min_num);
//        }
//        if (idx1 == m) {
//            while (idx2 < n)
//                ans.push_back(nums2[idx2++]);
//        } else {
//            while (idx1 < m)
//                ans.push_back(nums1[idx1++]);
//
//        }
//        nums1 = ans;
//        return;
//    }
};

void read_data(vector<int>& nums1, int& m, vector<int>& nums2, int& n) {
    cin >> m >> n;
    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        nums1.push_back(t);
    }
    for(int i = m; i < m + n; ++i)
        nums1.push_back(0);

    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums2.push_back(t);
    }
    return;
}

int main() {
    vector<int> nums1;
    int m;
    vector<int> nums2;
    int n;
    read_data(nums1, m, nums2, n);
    Solution solve;
    solve.merge(nums1, m, nums2, n);
    for (int num: nums1)
        cout <<  num << " ";
    cout << "\n";
    return 0;
}