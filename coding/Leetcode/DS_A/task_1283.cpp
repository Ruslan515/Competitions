//
// Created by omega515 on 03.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(vector<int> &nums, int div) {
        int sum = 0;
        int x;
        for (auto num: nums) {
            x = ceil(1.0 * num / div);
            sum += x;
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int minDiv = 1, maxDiv = pow(10, 6);
        int midDiv;
        int res;
        while (minDiv <= maxDiv) {
            midDiv = minDiv + (maxDiv - minDiv) / 2;
            res = check(nums, midDiv);
            if (res > threshold) {
                minDiv = midDiv + 1;
            } else {
                maxDiv = midDiv - 1;
            }
        }
        answer = minDiv;

        return answer;
    }
};

int main() {
    vector<int> nums;
    int threshold;
    int answer;
    Solution solve;

    nums = {1, 2, 5, 9}, threshold = 6;
    answer = 5;
    assert(answer == solve.smallestDivisor(nums, threshold));

    nums = {44, 22, 33, 11, 1}, threshold = 5;
    answer = 44;
    assert(answer == solve.smallestDivisor(nums, threshold));

    return 0;
}
