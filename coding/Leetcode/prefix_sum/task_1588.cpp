// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/?envType=problem-list-v2&envId=prefix-sum
// Created by omega515 on 06.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = arr.size();
        vector<int> sums;
        for (int i = 0; i < n; ++i) {
            answer += arr[i];
            sums.push_back(answer);
        }
        for (int size = 3; size <= n; size += 2) {
            int end;
            int tmp;
            for (int start = 0; start + size <= n; ++start) {
                end = start + size - 1;
                tmp = sums[end] - sums[start] + arr[start];
                answer += tmp;
            }
        }


        return answer;
    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {1, 4, 2, 5, 3};
    answer = 58;
    assert(answer == solve.sumOddLengthSubarrays(arr));

    arr = {1, 2};
    answer = 3;
    assert(answer == solve.sumOddLengthSubarrays(arr));

    arr = {10, 11, 12};
    answer = 66;
    assert(answer == solve.sumOddLengthSubarrays(arr));

    return 0;
}