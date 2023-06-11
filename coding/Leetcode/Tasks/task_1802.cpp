// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
// Created by ruslan515 on 10.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1;
        int right = maxSum;
        int answer = 0;

        int leftSum;
        int rightSum;
        int tempSum = leftSum + rightSum;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            int t = middle - index;
            leftSum = t * index + index * (index - 1) / 2;

            int rLen = (n - index - 1);
            int tRight = middle - rLen;
            int rightSum = tRight * rLen;
            int x = (n - index - 1) * (n - index - 2) / 2;
            rightSum += x;

            int totalSum = leftSum + middle + rightSum;

            if (totalSum > maxSum) {
                right = middle - 1;
            } else if (totalSum < maxSum) {
                answer = middle;
                left = middle + 1;
            } else {
                answer = middle;
                break;
            }
        }

        return answer;
    }
};

int main() {
    int n, index, maxSum;
    int answer;
    Solution solve;

    n = 4, index = 2, maxSum = 6;
    answer = 2;
    assert(answer == solve.maxValue(n, index, maxSum));

    n = 6, index = 1, maxSum = 10;
    answer = 3;
    assert(answer == solve.maxValue(n, index, maxSum));

    return 0;
}