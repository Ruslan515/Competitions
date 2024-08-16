// https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25
// Created by omega515 on 25.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums,
               int left_first,
               int left_second,
               int right_first,
               int right_second
    ) {
        int size = right_second - left_first;
        vector<int> v;
        int i = left_first, j = right_first;
        int n1 = left_second;
        int n2 = right_second;
        int x, y;
        while (i < n1 && j < n2) {
            x = nums[i];
            y = nums[j];
            if (x < y) {
                v.push_back(x);
                ++i;
            } else {
                v.push_back(y);
                ++j;
            }
        }
        if (i == n1 && j != n2) {
            for (; j < n2; ++j) {
                v.push_back(nums[j]);
            }
        } else if (j == n2 && i != n1) {
            for (; i < n1; ++i) {
                v.push_back(nums[i]);
            }
        }
        for (i = 0; i < size; ++i) {
            nums[left_first + i] = v[i];
        }

    }

    vector<int> sortArray(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        int n = nums.size();
        int
                left_first,
                left_second,
                right_first,
                right_second;
        for (int size = 1; size < n; size *= 2) {
            for (int i = 0; i < n; i += 2 * size) {
                left_first = i;
                left_second = i + size;
                if (left_second < n ) {
                    right_first = i + size;
                    right_second = min(i + 2 * size, n);
                    merge(
                            nums,
                            left_first, left_second,
                            right_first, right_second
                    );
                }
            }
        }


        return nums;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {5, 2, 3, 1};
    answer = {1, 2, 3, 5};
    assert(answer == solve.sortArray(nums));

    nums = {-4, 0, 7, 4, 9, -5, -1, 0, -7, -1};
    answer = {-7, -5, -4, -1, -1, 0, 0, 4, 7, 9};
    assert(answer == solve.sortArray(nums));

    nums = {5, 1, 1, 2, 0, 0};
    answer = {0, 0, 1, 1, 2, 5};
    assert(answer == solve.sortArray(nums));

    return 0;
}
