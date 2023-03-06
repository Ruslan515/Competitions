// https://leetcode.com/problems/kth-missing-positive-number/
// Created by ruslan515 on 06.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int answer = 0;
        int cnt = 0;
        set<int> st(arr.begin(), arr.end());
        for (int i = 1; i < 10001; ++i) {
            if (st.count(i) == 0) {
                ++cnt;
                if (cnt == k) {
                    answer = i;
                    break;
                }
            }
        }

        return answer;
    }
};

void read_data(vector<int> &arr, int &k) {
    cin >> k;
    int t;
    while (cin >> t)
        arr.push_back(t);
    return;
}

int main() {
    vector<int> arr;
    int k;
    read_data(arr, k);
    Solution solve;
    cout << solve.findKthPositive(arr, k);

    return 0;
}
