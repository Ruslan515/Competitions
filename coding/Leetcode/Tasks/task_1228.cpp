// https://leetcode.com/problems/missing-number-in-arithmetic-progression/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 25.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer;
        int n = arr.size();
        if (n == 2) {
            return (arr[0] + arr[1]) / 2;
        }
        if (n == 3) {
            int d1 = arr[1] - arr[0];
            if (arr[1] + d1 * 2 == arr[2]) {
                return arr[1] + d1;
            }
            d1 = arr[2] - arr[1];
            return arr[0] + d1;
        }
        unordered_set<int> st;
        int d;
        for (int i = 0; i < n - 1; ++i) {
            d = arr[i + 1] - arr[i];
            if (st.size() != 0) {
                if (st.find(d / 2) != st.end()) {
                    answer = arr[i] + d / 2;
                    break;
                } else {
                    if (st.find(2 * d) != st.end()) {
                        answer = arr[0] + d;
                        break;
                    }
                }
            } else {
                st.insert(d);
            }
        }


        return answer;
    }
};


int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {100, 300, 400};
    answer = 200;
    assert(answer == solve.missingNumber(arr));

    arr = {15, 13, 12};
    answer = 14;
    assert(answer == solve.missingNumber(arr));

    arr = {5, 7, 11, 13};
    answer = 9;
    assert(answer == solve.missingNumber(arr));

    return 0;
}