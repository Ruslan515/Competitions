// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Created by ruslan515 on 06.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        int n = arr.size();
        bool answer = true;
        for (int i = 2; i < n; ++i) {
            int dx = arr[i] - arr[i - 1];
            if (dx != d) {
                answer = false;
                break;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> arr;
    bool answer;
    Solution solve;

    arr = {3, 5, 1};
    answer = true;
    assert(solve.canMakeArithmeticProgression(arr) == answer);

    arr = {1, 2, 4};
    answer = false;
    assert(solve.canMakeArithmeticProgression(arr) == answer);

    return 0;
}