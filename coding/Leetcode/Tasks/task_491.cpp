// https://leetcode.com/problems/non-decreasing-subsequences/
// Created by ruslan515 on 20.01.23.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void comb(map<vector<int>, int>& mp, vector<int>& nums, vector<int>& data, int n, int len, int idx, int i) {
        if (idx == len) {
            bool label = true;
            for (int j = 1; j < len; ++j) {
                if (data[j] < data[j - 1]) {
                    label = false;
                    break;
                }
            }
            if (label){
                if (mp.count(data) == 0)
                    mp[data] = 1;
            }

        }

        if (i >= n)
            return;

        data[idx] = nums[i];
        comb(mp, nums, data, n, len, idx + 1, i + 1);
        comb(mp, nums, data, n, len, idx, i + 1);
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        map<vector<int>, int> mp;
        vector<int> temp;
        int n = nums.size();
        for (int len = 2; len <= n; ++len) {
            vector<int> data(len, 0);
            comb(mp,nums, data, n, len, 0, 0);
        }
        map<vector<int>, int> :: iterator it = mp.begin();
        for(; it != mp.end(); ++it) {
            ans.push_back(it->first);
        }

        return ans;
    }
};

//class Solution {
//public:
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        vector<vector<int>> ans;
//        map<vector<int>, int> mp;
//        vector<int> temp;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            int current = nums[i];
//            temp.push_back(current);
//            for (int length = 2; length < n - i; ++length) {
//
//            }
//
//
//            for(int j = i + 1; j < n; ++j) {
//                int num = nums[j];
//                if (num >= current) {
//                    temp.push_back(num);
//                }
//            }
//            int size = temp.size();
//            if (size >= 2) {
//                if (mp.count(temp) == 0) {
//                    mp[temp] = 1;
//                }
//            }
//        }
//        map<vector<int>, int> :: iterator it;
//        for(; it != mp.end(); ++it) {
//            ans.push_back(it->first);
//        }
//
//        return ans;
//    }
//};


void read_data(vector<int>& nums) {
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;

    vector<vector<int>> ans = solve.findSubsequences(nums);
    for (vector<int> vec: ans) {
        for (int a: vec) {
            cout << a << " ";
        }
        cout << "\n";
    }
    return 0;
}