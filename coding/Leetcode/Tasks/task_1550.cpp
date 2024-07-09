// https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01
// Created by omega515 on 01.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int> &arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool answer = false;
        int n = arr.size();
        if (n < 3) {
            return answer;
        }
        int right = 0;
        while (right < n - 2) {
            if (arr[right] % 2 == 1) {
                if (arr[right + 1] % 2 == 1 && arr[right + 2] % 2 == 1) {
                    answer = true;
                    break;
                } else if (arr[right + 2] % 2 == 1) {
                    right += 2;
                } else {
                    right += 3;
                }
            } else {
                ++right;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> arr;
    bool answer;
    Solution solve;

    arr = {1, 1, 1};
    answer = true;
    assert(answer == solve.threeConsecutiveOdds(arr));

    arr = {2, 6, 4, 1};
    answer = false;
    assert(answer == solve.threeConsecutiveOdds(arr));

    arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    answer = true;
    assert(answer == solve.threeConsecutiveOdds(arr));

    return 0;
}
