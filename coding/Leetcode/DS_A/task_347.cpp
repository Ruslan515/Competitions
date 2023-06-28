// https://leetcode.com/problems/top-k-frequent-elements/description/
// Created by ruslan515 on 27.06.23.
//

#include <bits/stdc++.h>

using namespace std;

//struct myComp {
//    constexpr bool operator()(
//            pair<int, int> const &a,
//            pair<int, int> const &b
//    ) const noexcept {
//        return a.second < b.second;
//    }
//};

typedef pair<int, int> pd;

// Structure of the condition
// for sorting the pair by its
// second elements
struct myComp {
    constexpr bool operator()(
            pair<int, int> const &a,
            pair<int, int> const &b)
    const noexcept {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (auto num: nums) {
            ++mp[num];
        }
//        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        priority_queue<pd, vector<pd>, myComp> pq;
        vector<int> answer;
        for (auto el: mp) {
            pq.push(el);
        }
        int count, val;
        for (int i = 0; i < k; ++i) {
            pair<int, int> el = pq.top();
            pq.pop();
            count = el.second;
            val = el.first;
            answer.push_back(val);
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    int k;
    Solution solve;

    nums = {1, 1, 1, 2, 2, 3}, k = 2;
    answer = {1, 2};
    assert(answer == solve.topKFrequent(nums, k));

    nums = {1}, k = 1;
    answer = {1};
    assert(answer == solve.topKFrequent(nums, k));

    return 0;
}