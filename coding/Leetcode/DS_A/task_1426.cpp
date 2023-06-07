// https://leetcode.com/problems/counting-elements/description/
// Created by ruslan515 on 07.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &arr) {
        map<int, int> nums;
        for (int num: arr) {
            ++nums[num];
        }

        int answer = 0;
        map<int, int>::iterator it = nums.begin();
        for (; it != nums.end(); ++it) {
            int next = it->first + 1;
            if (nums.find(next) != nums.end()) {
                int count = it->second;
                answer += count;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {1, 1, 2};
    answer = 2;
    assert(answer == solve.countElements(arr));

    arr = {1, 1, 2, 2};
    answer = 2;
    assert(answer == solve.countElements(arr));

    arr = {1, 2, 3};
    answer = 2;
    assert(answer == solve.countElements(arr));

    arr = {1, 1, 3, 3, 5, 5, 7, 7};
    answer = 0;
    assert(answer == solve.countElements(arr));

    return 0;
}