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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        map<vector<int>, int> mp;
        vector<int> temp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int current = nums[i];
            temp.push_back(current);
            for (int length = 2; length < n - i; ++length) {

            }


            for(int j = i + 1; j < n; ++j) {
                int num = nums[j];
                if (num >= current) {
                    temp.push_back(num);
                }
            }
            int size = temp.size();
            if (size >= 2) {
                if (mp.count(temp) == 0) {
                    mp[temp] = 1;
                }
            }
        }
        map<vector<int>, int> :: iterator it;
        for(; it != mp.end(); ++it) {
            ans.push_back(it->first);
        }

        return ans;
    }
};


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