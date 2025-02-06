// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06
// Created by omega515 on 06.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = nums.size();
        if (n < 4) {
            return answer;
        }
        unordered_map<int, vector<int>> mp;
        int tmp, x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                x = nums[i];
                y = nums[j];
                tmp = x * y;
                mp[tmp].insert(mp[tmp].end(), {x, y});
            }
        }
        vector<int> v;
        for (const auto &pair: mp) {
            v = pair.second;
            int size = v.size();
            if (size > 2) {
                size /= 2;
                tmp = (size - 1) * size / 2;
                tmp *= 8;
                answer += tmp;
            }
        }

        return answer;
    }
};


int main() {
    vector<int> nums;
    int answer;
    Solution solve;

    nums = {2, 3, 4, 6};
    answer = 8;
    assert(answer == solve.tupleSameProduct(nums));

    nums = {1, 2, 4, 5, 10};
    answer = 16;
    assert(answer == solve.tupleSameProduct(nums));

    return 0;
}

