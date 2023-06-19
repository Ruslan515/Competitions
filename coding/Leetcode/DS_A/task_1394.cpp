// https://leetcode.com/problems/sum-of-unique-elements/
// Created by ruslan515 on 19.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLucky(vector<int> &arr) {
        unordered_map<int, int> mp;
        for (auto num: arr) {
            ++mp[num];
        }

        int key, value, maxValue = -1;
        for (auto el: mp) {
            key = el.first;
            value = el.second;
            if (key == value) {
                maxValue = max(maxValue, value);
            }
        }

        return maxValue;
    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {2, 2, 3, 4};
    answer = 2;
    assert(answer == solve.findLucky(arr));

    arr = {1, 2, 2, 3, 3, 3};
    answer = 3;
    assert(answer == solve.findLucky(arr));

    arr = {2, 2, 2, 3, 3};
    answer = -1;
    assert(answer == solve.findLucky(arr));

    return 0;
}
