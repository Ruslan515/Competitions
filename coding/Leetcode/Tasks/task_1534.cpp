// https://leetcode.com/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14
// Created by omega515 on 14.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = arr.size();
        int x, y, z;
        for (int i = 0; i < n; ++i) {
            x = arr[i];
            for (int j = i + 1; j < n; ++j) {
                y = arr[j];
                for (int k = j + 1; k < n; ++k) {
                    z = arr[k];
                    if ((abs(x - y) <= a) && (abs(y - z) <= b) && (abs(x - z) <= c)) {
                        ++answer;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> arr;
    int a, b, c;
    int answer;
    Solution solve;

    arr = {3, 0, 1, 1, 9, 7}, a = 7, b = 2, c = 3;
    answer = 4;
    assert(answer == solve.countGoodTriplets(arr, a, b, c));

    arr = {1, 1, 2, 2, 3}, a = 0, b = 0, c = 1;
    answer = 0;
    assert(answer == solve.countGoodTriplets(arr, a, b, c));

    return 0;
}
