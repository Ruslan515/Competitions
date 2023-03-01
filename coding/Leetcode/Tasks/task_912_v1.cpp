// https://leetcode.com/problems/sort-an-array/
// Created by ruslan515 on 01.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        int BSI, BI, LBI, RBI, MI;
        int LB, MB, RB;
        for (BSI = 1; BSI < n; BSI *= 2) {
            for (BI = 0; BI < n - BSI; BI += 2 * BSI) {
                LBI = 0;
                RBI = 0;
                LB = BI;
                MB = BI + BSI;
                RB = BI + 2 * BSI;
                RB = min(RB, n);
                vector<int> SortedBlock(RB - LB);
//                int *SortedBlock = new int[RB - LB];
                while (LB + LBI < MB && MB + RBI < RB) {
                    if (nums[LB + LBI] < nums[MB + RBI]) {
                        SortedBlock[LBI + RBI] = nums[LB + LBI];
                        ++LBI;
                    } else {
                        SortedBlock[LBI + RBI] = nums[MB + RBI];
                        ++RBI;
                    }
                }
                while (LB + LBI < MB) {
                    SortedBlock[LBI + RBI] = nums[LB + LBI];
                    ++LBI;
                }
                while (MB + RBI < RB) {
                    SortedBlock[LBI + RBI] = nums[MB + RBI];
                    ++RBI;
                }
                for (MI = 0; MI < LBI + RBI; MI++) {
                    nums[LB + MI] = SortedBlock[MI];
                }
//                delete SortedBlock;
            }
        }
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