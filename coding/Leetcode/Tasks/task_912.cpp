// https://leetcode.com/problems/sort-an-array/
// Created by ruslan515 on 01.03.23.
//

// merge sort

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int middle = l + (r - l) / 2;
        mergeSort(nums, l, middle);
        mergeSort(nums, middle + 1, r);

        vector<int> buffer(nums.size());
        copy(begin(nums), end(nums), begin(buffer));

        int i = l;
        int j = middle + 1;
        for(int k = l; k <= r; ++k) {
            if (i > middle) {
                nums[k] = buffer[j];
                ++j;
            } else if (j > r) {
                nums[k] = buffer[i];
                ++i;
            } else if (buffer[j] < buffer[i]) {
                nums[k] = buffer[j];
                ++j;
            } else {
                nums[k] = buffer[i];
                ++i;
            }
        }

    }

    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};

void read_data(vector<int> &nums) {
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;
    for (int i: solve.sortArray(nums)) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}