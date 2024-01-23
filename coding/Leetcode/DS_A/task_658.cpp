// https://leetcode.com/problems/find-k-closest-elements/description/
// Created by omega515 on 20.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> heap;

        for (int num: arr) {
            int distance = abs(x - num);
            heap.push(pair(distance, num));
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> ans;
        while (heap.size() > 0) {
            ans.push_back(heap.top().second); heap.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
//typedef pair<int, int> pd;
//
//struct myComp {
//    constexpr bool operator()(
//            pd const &a,
//            pd const &b
//    )
//    const noexcept {
//        if (a.second > b.second) {
//            return true;
//        } else if (a.second == b.second) {
//            return a.first > b.first;
//        } else {
//            return a.second < b.second;
//        }
//
//    }
//};
//
//class Solution {
//public:
//    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
//        vector<int> answer(k);
//        map<int, int> mp;
//        for (auto y: arr) {
//            mp[y] = abs(y - x);
//        }
//        priority_queue<pd, vector<pd>, myComp> heap;
//
//        for (pair<int, int> p: mp) {
//            heap.push(p);
//            if (heap.size() > k) heap.pop();
//        }
//
//        for (int i = k - 1; i >= 0; --i) {
//            answer[i] = heap.top().first;
//            heap.pop();
//        }
//        sort(answer.begin(), answer.end());
//
//        return answer;
//    }
//
////    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
////        vector<int> answer(k);
////        unordered_map<int, int> mp;
////        for (auto y: arr) {
////            mp[y] = abs(y - x);
////        }
////        auto comp = [&mp](int n1, int n2) {
////            if (mp[n1] < mp[n2]) {
////                return true;
////            } else if (mp[n1] == mp[n2]) {
////                return n1 < n2;
////            }
////        };
////        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
////        for (pair<int, int> p: mp) {
////            heap.push(p.first);
////            if (heap.size() > k) heap.pop();
////        }
////        for (int i = k - 1; i >= 0; --i) {
////            answer[i] = heap.top();
////            heap.pop();
////        }
////        sort(answer.begin(), answer.end());
////
////        return answer;
////    }
//};

int main() {
    vector<int> arr;
    int k, x;
    vector<int> answer;
    Solution solve;

    arr = {1, 1, 1, 10, 10, 10}, k = 1, x = 9;
    answer = {10};
    assert(answer == solve.findClosestElements(arr, k, x));

    arr = {1, 2, 3, 4, 5}, k = 4, x = 3;
    answer = {1, 2, 3, 4};
    assert(answer == solve.findClosestElements(arr, k, x));

    arr = {1, 2, 3, 4, 5}, k = 4, x = 3;
    answer = {1, 2, 3, 4};
    assert(answer == solve.findClosestElements(arr, k, x));

    return 0;
}