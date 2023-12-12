// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/?envType=daily-question&envId=2023-12-11
// Created by omega515 on 11.12.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int answer = 0;
        unordered_map<int, int> mp;
        int count = 0;
        for (int num: arr) {
            ++mp[num];
            if (mp[num] > count) {
                answer = num;
                count = mp[num];
            }

        }

        return answer;
    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    answer = 6;
    assert(answer == solve.findSpecialInteger(arr));

    arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    answer = 6;
    assert(answer == solve.findSpecialInteger(arr));

    return 0;
}
