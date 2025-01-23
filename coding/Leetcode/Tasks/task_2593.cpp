// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13
// Created by omega515 on 13.12.24.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pr;

class Solution {
public:
//    struct less_then_less {
//        template<typename T, typename U>
//        bool operator()(T const &lhs, U const &rhs) const {
//            if (lhs.first < rhs.first) return false;
//            if (rhs.first < lhs.first) return true;
//            return lhs.second < lhs.second;
//        }
//    };

//    struct less_then_less {
//        constexpr bool operator()(
//                pr const &a,
//                pr const &b)
//        const noexcept {
//            return a.first != b.first ? a.first > b.first : a.second > b.second;
//        }
//    };

    struct less_then_less {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        }
    };

    long long findScore(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long score = 0;
        int n = nums.size();
        vector<int> used(n, 0);
//        priority_queue<pr, vector<pr>, less_then_less> priorityQueue;
        priority_queue<pr, vector<pr>, greater<pr>> priorityQueue;

        for (int i = 0; i < n; ++i) {
            priorityQueue.push({nums[i], i});
        }
        pr prVal;
        int val, idx, valUsed;
        while (!priorityQueue.empty()) {
            prVal = priorityQueue.top();
            priorityQueue.pop();
            val = prVal.first;
            idx = prVal.second;
            valUsed = used[idx];
            if (valUsed != 0) {
                continue;
            }
            score += val;
            used[idx] = 1;
            int prevIdx = idx - 1, nextIdx = idx + 1;
            if (prevIdx >= 0 && used[prevIdx] == 0) {
                used[prevIdx] = 1;
            }
            if (nextIdx < n && used[nextIdx] == 0) {
                used[nextIdx] = 1;
            }

        }


        return score;
    }
};

int main() {
    vector<int> nums;
    Solution solve;
    long long answer;

    nums = {2, 1, 3, 4, 5, 2};
    answer = 7;
    assert(answer == solve.findScore(nums));

    answer = 5;
    nums = {2, 3, 5, 1, 3, 2};
    assert(answer == solve.findScore(nums));

    return 0;
}