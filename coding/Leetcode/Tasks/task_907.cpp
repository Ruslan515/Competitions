// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20
// Created by omega515 on 20.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MODULO = pow(10, 9) + 7;

    int sumSubarrayMins(vector<int> &arr) {
        int answer = 0;
        int n = arr.size();
        int val;
        for (int i = 0; i < n; ++i) {
            val = arr[i];
            int left = i, right = i;
            while (left != 0 && arr[left] >= val) {
                --left;
            }
            while (right < n && arr[right] >= val) {
                ++right;
            }
            int x = i - left + 1;
            int y = right - i;
            int tmp = x * y * val;
            answer += tmp;

        }

        return answer % MODULO;
    }
//    int sumSubarrayMins(vector<int> &arr) {
//        int answer = 0;
//        int n = arr.size();
//        for (int i = 0; i < n; ++i) {
//            arr[i] *= -1;
//        }
//        int tmp;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i; j < n; ++j) {
//                auto start = arr.begin() + i;
//                auto end = arr.begin() + j + 1;
//                vector<int> result(j - i + 1);
//                copy(start, end, result.begin());
//                priority_queue<int> heap(result.begin(), result.end());
//                tmp = heap.top();
//                answer += tmp * (-1);
//            }
//        }
//
//        return answer % MODULO;
//    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {3, 1, 2, 4};
    answer = 17;
    assert(answer == solve.sumSubarrayMins(arr));

    arr = {11, 81, 94, 43, 3};
    answer = 444;
    assert(answer == solve.sumSubarrayMins(arr));

    return 0;
}