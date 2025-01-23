//
// Created by omega515 on 08.12.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<int> answer;
        int idx, step, res;
        for (int i = 0; i < n; ++i) {
            step = nums[i];
            if (step > 0) {
                idx = (i + step) % n;
                res = nums[idx];
                answer.push_back(res);
            } else if (step < 0) {
                idx = (i + step) % n;
                if (idx < 0) {
                    idx = n + idx;
                }

                res = nums[idx];
                answer.push_back(res);
            } else {
                answer.push_back(step);
            }
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {-2, 5, -3};
    answer = {5, -2, -3};
    assert(answer == solve.constructTransformedArray(nums));

    nums = {-1, 4, -1};
    answer = {-1, -1, 4};
    assert(answer == solve.constructTransformedArray(nums));

    nums = {3, -2, 1, 1};
    answer = {1, 1, 1, 3};
    assert(answer == solve.constructTransformedArray(nums));


    return 0;
}
