// https://leetcode.com/problems/intersection-of-two-arrays-ii/solutions/
// Created by ruslan515 on 18.01.23.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void insert_to_map(vector<int>& nums, map<int, int>& hashmap) {
        for (int num: nums) {
            if (hashmap.count(num))
                ++hashmap[num];
            else
                hashmap[num] = 1;
        }
        return;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> map1, map2;
        insert_to_map(nums1, map1);
        insert_to_map(nums2, map2);
        map<int, int> :: iterator it;
        map<int, int> mp;
        int size1 = map1.size();
        int size2 = map2.size();
        if (size1 < size2) {
            it = map1.begin();
            mp = map2;
        } else {
            it = map2.begin();
            mp = map1;
        }
        for(int i = 0; i < min(size1, size2); ++it, ++i) {
            int key = it->first;
            int value = it->second;
            if (mp.count(key)) {
                int value1 = mp[key];
                int cnt = min(value, value1);
                for (int j = 0; j < cnt; ++j)
                    ans.push_back(key);
            }
        }

        return ans;
    }
};

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
    vector<int> ans = solve.intersect(nums1,nums2);
    for (int num: ans)
        cout <<  num << " ";
    cout << "\n";
    return 0;
}