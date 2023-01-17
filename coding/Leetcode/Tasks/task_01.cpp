// https://leetcode.com/problems/two-sum/description/
// Created by ruslan515 on 17.01.23.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, vector<int>> my_map;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int t = target - num;
            map<int, vector<int>> :: iterator it_find;
            it_find = my_map.find(t);
            if (it_find != my_map.end()) {
                int idx1 = it_find->second[1];
                ans.push_back(idx1);
                ans.push_back(i);
                break;
            }
            vector<int> temp;
            temp.push_back(t);
            temp.push_back(i);
            my_map[num] = temp;
        }

        return ans;
    }
};

void read_data(vector<int>& nums, int& target) {
    cin >> target;
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    int target;
    vector<int> nums;
    read_data(nums, target);
    Solution solve;
    vector<int> ans = solve.twoSum(nums, target);
    for (int a: ans)
        cout << a << " ";
    cout << "\n";

    return 0;
}