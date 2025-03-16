// https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07
// Created by omega515 on 07.03.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        set<int> set1;
        for (int i = 2; i <= right; ++i) {
            set1.insert(i);
        }
        int p = 2;
        int start = p * p;
        while (start <= right) {
            for (int j = start; j <= right; j += p) {
                set1.erase(j);
            }
            auto it = set1.upper_bound(p);
            if (it == set1.end()) {
                break;
            }
            p = *it;
            start = p * p;
        }

        vector<int> v;
        for (auto it = set1.begin(); it != set1.end(); ++it) {
            int val = *it;
            if (val >= left && val <= right) {
                v.push_back(val);
            }
        }
        if (v.size() < 2) {
            return {-1, -1};
        }

        int prev = v[0];
        int curr, diff;
        int minDiff = 1e6;
        int a, b;
        for (int i = 1; i < v.size(); ++i) {
            curr = v[i];
            diff = curr - prev;
            if (diff < minDiff) {
                minDiff = diff;
                a = prev;
                b = curr;
            }
            prev = curr;
        }


//        auto itStart = set1.lower_bound(left);
//        auto itEnd = set1.upper_bound(right);
//        int prev = *itStart;
//        int curr, diff;
//        int minDiff = 1e6;
//        int a, b;
//        itStart++;
//        if (itStart == itEnd) {
//            return {-1, -1};
//        }
//        for (auto it = itStart; it != itEnd; ++it) {
//            curr = *it;
//            diff = curr - prev;
//            if (diff < minDiff) {
//                minDiff = diff;
//                a = prev;
//                b = curr;
//            }
//
//            prev = curr;
//        }
//
        vector<int> answer{a, b};
        return answer;
    }
};

int main() {
    int left, right;
    vector<int> answer;
    Solution solve;

    left = 19, right = 31;
    answer = {29, 31};
    assert(answer == solve.closestPrimes(left, right));

    left = 4, right = 6;
    answer = {-1, -1};
    assert(answer == solve.closestPrimes(left, right));

    left = 10, right = 19;
    answer = {11, 13};
    assert(answer == solve.closestPrimes(left, right));

    return 0;
}

