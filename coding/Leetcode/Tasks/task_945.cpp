// https://leetcode.com/problems/minimum-increment-to-make-array-unique/?envType=daily-question&envId=2024-06-14
// Created by omega515 on 14.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        int answer = 0;
        unordered_map<int, int> mp;
        set<int> keys;
        int count = 0;
        for (int num: nums) {
            ++mp[num];
            if (mp[num] > 1) {
                ++count;
            }
            keys.insert(num);
        }
        vector<int> k;
        for (int key: keys) {
            k.push_back(key);
        }
        priority_queue<pair<int, int>> pq;
        int l, r, diff;
        for (int i = 0; i < k.size() - 1; ++i) {
            l = k[i];
            r = k[i + 1];
            if (l != (r - 1)) {
                pq.push(make_pair(-1 * (l + 1), -1 * r));
            }
        }
        pq.push(make_pair(-1 * k[k.size() - 1] - 1, -1 * INT_MAX));

        for (int key: keys) {
            int val = mp[key];
            if (val != 1) {
                for (; val != 1; --val) {
                    while (true) {
                        pair<int, int> lr = pq.top();
                        pq.pop();
                        l = (-1) * lr.first;
                        r = (-1) * lr.second;
                        if (key < l) {
                            break;
                        }
                    }
                    diff = l - key;
                    answer += diff;
                    ++l;
                    if (l < r) {
                        pq.push(make_pair(-1 * l, -1 * r));
                    }
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

    nums = {7, 2, 7, 2, 1, 4, 3, 1, 4, 8};
    answer = 16;
    assert(answer == solve.minIncrementForUnique(nums));

    nums = {0, 2, 2};
    answer = 1;
    assert(answer == solve.minIncrementForUnique(nums));

    nums = {3, 2, 1, 2, 1, 7};
    answer = 6;
    assert(answer == solve.minIncrementForUnique(nums));

    nums = {1, 2, 3, 7, 8, 8, 9, 12, 15};
    answer = 2;
    assert(answer == solve.minIncrementForUnique(nums));

    nums = {1, 2, 2};
    answer = 1;
    assert(answer == solve.minIncrementForUnique(nums));

    return 0;
}
