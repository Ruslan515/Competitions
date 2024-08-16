// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
// Created by omega515 on 23.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        vector<int> answer;
//        struct cmp {
//            bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
//                return a.second != b.second ? a.second < b.second : a.first > b.first;
//            }
//        };
        auto cmp = [](pair<int, int> const &a, pair<int, int> const &b) {
            return a.second != b.second ? a.second < b.second : a.first > b.first;
        };

        struct myComp {
            constexpr bool operator()(
                    pair<int, int> const &a,
                    pair<int, int> const &b)
            const noexcept {
                return a.second != b.second ? a.second < b.second : a.first > b.first;;
            }
        };

        map<int, int> mp;
        for (int num: nums) {
            ++mp[num];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        int key, value;
        for (pair item: mp) {
            key = -1 * item.first;
            value = -1 * item.second;
            pq.push({key, value});
        }
        while (!pq.empty()) {
            pair<int, int> item = pq.top();
            pq.pop();
            key = -1 * item.first;
            value = -1 * item.second;
            for (int i = 0; i < value; ++i) {
                answer.push_back(key);
            }
        }


        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {1, 1, 2, 2, 2, 3};
    answer = {3, 1, 1, 2, 2, 2};
    assert(answer == solve.frequencySort(nums));

    nums = {2, 3, 1, 3, 2};
    answer = {1, 3, 3, 2, 2};
    assert(answer == solve.frequencySort(nums));

    nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    answer = {5, -1, 4, 4, -6, -6, 1, 1, 1};
    assert(answer == solve.frequencySort(nums));

    return 0;
}
