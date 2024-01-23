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

//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        // O(1) time
//        if (k == nums.size()) {
//            return nums;
//        }
//
//        // 1. Build hash map: element and how often it appears
//        // O(N) time
//        map<int, int> count_map;
//        for (int n : nums) {
//            count_map[n] += 1;
//        }
//
//        //Initialise a heap with the most frequent elements at the top
//        auto comp = [&count_map](int n1, int n2) { return count_map[n1] > count_map[n2]; };
//        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
//
//        // 2. Keep k top frequent elements in the heap
//        // O(N log k) < O(N log N) time
//        for (pair<int, int> p : count_map) {
//            heap.push(p.first);
//            if (heap.size() > k) heap.pop();
//        }
//
//        // 3. Build an output array
//        // O(k log k) time
//        vector<int> top(k);
//        for (int i = k - 1; i >= 0; i--) {
//            top[i] = heap.top();
//            heap.pop();
//        }
//        return top;
//    }
//};

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