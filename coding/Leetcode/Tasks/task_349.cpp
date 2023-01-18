// https://leetcode.com/problems/intersection-of-two-arrays/description/
// Created by ruslan515 on 18.01.23.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> set1;
        for(int num: nums1)
            set1.insert(num);

        for(int num: nums2) {
            if (set1.count(num)) {
                ans.push_back(num);
                set1.erase(num);
            }
        }
        return ans;
    }
};

//class Solution {
//public:
//    void insert_to_set(vector<int>& nums, set<int>& st) {
//        for (int num: nums) {
//            st.insert(num);
//        }
//        return;
//    }
//
//    void insert_ans(vector<int>& ans, set<int> set_small, set<int> set_big) {
//        set<int> :: iterator it = set_small.begin();
//        for(; it != set_small.end(); ++it) {
//            int num = *it;
//            if (set_big.count(num))
//                ans.push_back(num);
//        }
//        return;
//    }
//
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> ans;
//        set<int> set1;
//        set<int> set2;
//        insert_to_set(nums1, set1);
//        insert_to_set(nums2, set2);
//        int size1 = set1.size();
//        int size2 = set2.size();
//        if (size1 < size2) {
//            insert_ans(ans, set1, set2);
//        } else {
//            insert_ans(ans, set2, set1);
//        }
//        return ans;
//    }
//};

void read_data(vector<int>& nums1, vector<int>& nums2) {
    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums1.push_back(t);
    }

    for(int i = 0; i < m; ++i) {
        cin >> t;
        nums2.push_back(t);
    }

    return;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    read_data(nums1, nums2);
    Solution solve;
    vector<int> ans = solve.intersection(nums1,nums2);
    for (int num: ans)
        cout <<  num << " ";
    cout << "\n";
    return 0;
}