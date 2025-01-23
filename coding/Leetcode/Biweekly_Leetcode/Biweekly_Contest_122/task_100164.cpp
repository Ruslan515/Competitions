// https://leetcode.com/contest/biweekly-contest-122/problems/minimize-length-of-array-using-operations/
// Created by omega515 on 20.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNotZero(vector<int> &nums, int start) {
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                return i;
            }
        }
        return -1;
    }

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    int minimumArrayLength(vector<int> &nums) {
        if (nums.size() == 1 || nums.size() == 2) {
            return 1;
        }
        int gcd_value = std::accumulate(nums.begin(), nums.end(), nums[0],
                                        [](int a, int b) {
                                            while (b != 0) {
                                                int temp = b;
                                                b = a % b;
                                                a = temp;
                                            }
                                            return a;
                                        });
        int count = 0;
        for (auto num: nums) {
            if (num % gcd_value == 0) {
                count++;
            }
        }
        if (gcd_value == 1) {
            return 1;
        } else if (count == nums.size() ) {
            return 2;
        }
        return count;
    }

//    int minimumArrayLength(vector<int> &nums) {
//        if (nums.size() == 1) {
//            return 1;
//        }
//        int answer = 2;
//        // Find the GCD of all numbers in the array
//        int gcd_val = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//            gcd_val = gcd(gcd_val, nums[i]);
//        }
//
//        // Divide all numbers by the GCD
//        for (int i = 0; i < nums.size(); i++) {
//            nums[i] /= gcd_val;
//        }
//
//        // Subtract the smallest number from each number
//        int min_num = *std::min_element(nums.begin(), nums.end());
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            nums[i] -= min_num;
//            if (nums[i] != 0) {
//                ++count;
//            }
//        }
//
//        // Return the minimum length
//        if (count == 2) {
//            answer = 1;
//        };
//        return answer;
//    }
//    int minimumArrayLength(vector<int> &nums) {
//        int answer = INT_MAX;
//        int i, j, tmp, val1, val2;
//        while (true) {
//            i = findNotZero(nums, 0);
//            if (i != -1) {
//                j = findNotZero(nums, i + 1);
//                if (j != -1) {
//                    val1 = nums[i];
//                    val2 = nums[j];
//                    tmp = val1 % val2;
//                    nums.push_back(tmp);
//                    nums.erase(nums.begin() + j);
//                    nums.erase(nums.begin() + i);
//                } else {
//                    break;
//                }
//            } else {
//                break;
//            }
//
//        }
//        answer = nums.size();
//
//        return answer;
//    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {4,6,2,6,4};
    answer = 1;
    assert(answer == solve.minimumArrayLength(nums));

    nums = {2, 4};
    answer = 1;
    assert(answer == solve.minimumArrayLength(nums));

    nums = {3};
    answer = 1;
    assert(answer == solve.minimumArrayLength(nums));

    nums = {1, 4, 3, 1};
    answer = 1;
    assert(answer == solve.minimumArrayLength(nums));

    nums = {5, 5, 5, 10, 5};
    answer = 2;
    assert(answer == solve.minimumArrayLength(nums));


    nums = {2, 3, 4};
    answer = 1;
    assert(answer == solve.minimumArrayLength(nums));

    nums = {1, 4};
    answer = 1;
    assert(answer == solve.minimumArrayLength(nums));


    return 0;
}

