// https://leetcode.com/contest/weekly-contest-351/problems/number-of-beautiful-pairs/
// Created by Ruslan Khalikov on 25.06.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int getFirstNumber(int x) {
        int answer = 0;
        while (x >= 10) {
            x /= 10;
        }
        return x;
    }

    int countBeautifulPairs(vector<int> &nums) {
        int answer = 0;
        int n = nums.size();
        int x, y;
        for (int i = 0; i < n - 1; ++i) {
            x = getFirstNumber(nums[i]);

            for (int j = i + 1; j < n; ++j) {
                y = nums[j] % 10;
                if (gcd(x, y) == 1) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {35, 52, 74, 92, 25, 65, 77, 1, 73, 32};
    answer = 37;
    assert(answer == solve.countBeautifulPairs(nums));


    nums = {756, 1324, 2419, 495, 106, 111, 1649, 1474, 2001, 1633,
            273, 1804, 2102, 1782, 705, 1529, 1761, 1613, 111,
            186, 412};
    answer = 183;
    assert(answer == solve.countBeautifulPairs(nums));

    nums = {11, 21, 12};
    answer = 2;
    assert(answer == solve.countBeautifulPairs(nums));

    nums = {2, 5, 1, 4};
    answer = 5;
    assert(answer == solve.countBeautifulPairs(nums));

    return 0;
}
