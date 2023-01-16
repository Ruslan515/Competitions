//
// Created by ruslan515 on 16.01.23.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans = false;
        if (k == 0)
            return ans;
        int n = nums.size();
        set<int> my_set;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (my_set.count(num)) {
                ans = true;
                return ans;
            } else {
                my_set.insert(num);
            }
            if (my_set.size() > k) {
                int del_num = nums[i - k];
                my_set.erase(del_num);
            }
        }
        return ans;
    }
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        bool ans = false;
//        if (k == 0)
//            return ans;
//        int n = nums.size();
//        set<int> my_set;
//        for (int i = 0; i <= k && i < n; ++i) {
//            int num = nums[i];
//            if (my_set.count(num)) {
//                ans = true;
//                return ans;
//            } else {
//                my_set.insert(num);
//            }
//        }
//
//        for (int i = k + 1; i < n; ++i) {
//            int del_num = nums[i - k - 1];
//            my_set.erase(del_num);
//            int num = nums[i];
//            if (my_set.count(num)) {
//                ans = true;
//                return ans;
//            } else {
//                my_set.insert(num);
//            }
//        }
//
//        return ans;
//    }

//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        bool ans = false;
//        int n = nums.size();
//
//        int end = n - k + 1;
//        for (int i = 0; i <= end; ++i) {
//            set<int> my_set;
//            int end_j = i + k + 1;
//            for (int j = i; j < end_j && j < n; ++j) {
//                int num = nums[j];
//                if (my_set.count(num)) {
//                    ans = true;
//                    return ans;
//                } else {
//                    my_set.insert(num);
//                }
//            }
//        }
//
//        return ans;
//    }
};

void read_data(vector<int>& nums, int& k) {
    cin >> k;
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    int k;
    read_data(nums, k);
    Solution solve;
    cout << solve.containsNearbyDuplicate(nums, k);
    return 0;
}