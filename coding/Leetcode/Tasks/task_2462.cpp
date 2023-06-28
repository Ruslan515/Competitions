// https://leetcode.com/problems/total-cost-to-hire-k-workers/
// Created by ruslan515 on 26.06.23.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        ll cost = 0;
        int n = costs.size();
        int idxLeft = candidates, idxRight = n - candidates - 1;
        if (idxRight < idxLeft) {
            for (int i = 0; i < k; ++i) {
                make_heap(costs.begin(), costs.end(), greater<int>());
                cost += costs[0];
                pop_heap(costs.begin(), costs.end(), greater<int>());
                costs.pop_back();
            }
            return cost;
        }
        vector<int> left(costs.begin(), costs.begin() + candidates);
        vector<int> right(costs.end() - candidates, costs.end());

        make_heap(right.begin(), right.end(), greater<int>());
        make_heap(left.begin(), left.end(), greater<int>());
        int minLeft, minRight;

        for (int i = 0; i < k; ++i) {
            if (!left.empty() && !right.empty()) {
                minLeft = left[0];
                minRight = right[0];
                if (minLeft <= minRight) {
                    cost += (ll) minLeft;
                    pop_heap(left.begin(), left.end(), greater<int>());
                    left.pop_back();
                    if (idxLeft <= idxRight) {
                        left.push_back(costs[idxLeft]);
                        ++idxLeft;
                        push_heap(left.begin(), left.end(), greater<int>());
                    }
                } else {
                    cost += (ll) minRight;
                    pop_heap(right.begin(), right.end(), greater<int>());
                    right.pop_back();
                    if (idxRight >= idxLeft) {
                        right.push_back(costs[idxRight]);
                        --idxRight;
                        push_heap(right.begin(), right.end(), greater<int>());
                    }
                }
            } else if (left.empty()) {
                cost += (ll) right[0];
                pop_heap(right.begin(), right.end(), greater<int>());
                right.pop_back();
            } else {
                cost += (ll) left[0];
                pop_heap(left.begin(), left.end(), greater<int>());
                left.pop_back();
            }
        }

        return cost;
    }
};

int main() {
    vector<int> costs;
    int k;
    int candidates;
    long long answer;
    Solution solve;

    costs = {25, 65, 41, 31, 14, 20, 59, 42, 43, 57, 73, 45, 30, 77, 17, 38, 20, 11, 17, 65, 55, 85, 74, 32,
             84}, k = 24, candidates = 8;
    answer = 1035;
    assert(answer == solve.totalCost(costs, k, candidates));

    costs = {57, 33, 26, 76, 14, 67, 24, 90, 72, 37, 30}, k = 11, candidates = 2;
    answer = 526;
    assert(answer == solve.totalCost(costs, k, candidates));

    costs = {1, 2, 4, 1}, k = 3, candidates = 3;
    answer = 4;
    assert(answer == solve.totalCost(costs, k, candidates));

    costs = {31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58}, k = 11, candidates = 2;
    answer = 241;
    assert(answer == solve.totalCost(costs, k, candidates));

    costs = {17, 12, 10, 2, 7, 2, 11, 20, 8}, k = 3, candidates = 4;
    answer = 11;
    assert(answer == solve.totalCost(costs, k, candidates));


    return 0;
}