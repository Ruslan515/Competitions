//
// Created by ruslan515 on 16.01.23.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (const int n: nums)
            if (s.count(n)) return true;
            else s.insert(n);
        return false;

    }
};

//    bool containsDuplicate(vector<int>& nums) {
//        bool ans = false;
//        map<int, int> count;
//        map<int, int> :: iterator it;
//        for (int num: nums) {
//            it = count.find(num);
//            if (it == count.end()) {
//                count[num] = 1;
//            } else {
//                ans = true;
//                break;
//            }
//        }
//        return ans;
//    }
//};

//    bool containsDuplicate(vector<int>& nums) {
//        ios_base::sync_with_stdio(0);
//        cin.tie(0);
//        cout.tie(0);
//
//        bool ans = false;
//        map<int, int> count;
//        for (auto num: nums) {
//            count[num]++;
//            if (count[num] > 1) {
//                ans = true;
//                break;
//            }
//        }
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
    cout << solve.containsDuplicate(nums);
    return 0;
}