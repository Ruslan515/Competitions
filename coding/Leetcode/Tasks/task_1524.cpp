// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
// Created by omega515 on 25.02.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long M = 1000000007;
        int answer = 0;
        int n = arr.size();
        int sums = 0;
        int cntOdd = 0, cntEven = 0;
        for (int i = 0; i < n; ++i) {
            sums += arr[i];
            if (sums % 2 == 0) {
                answer += cntOdd;
                ++cntEven;
            } else {
                answer += cntEven + 1;
                ++cntOdd;
            }
            answer %= M;
        }

        return answer;
    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {1, 3, 5};
    answer = 4;
    assert(answer == solve.numOfSubarrays(arr));

    arr = {2, 4, 6};
    answer = 0;
    assert(answer == solve.numOfSubarrays(arr));

    arr = {1, 2, 3, 4, 5, 6, 7};
    answer = 16;
    assert(answer == solve.numOfSubarrays(arr));

    return 0;
}
