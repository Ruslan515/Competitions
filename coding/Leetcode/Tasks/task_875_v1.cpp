// https://leetcode.com/problems/koko-eating-bananas/description/
// Created by omega515 on 21.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(vector<int> &piles, int h, int k) {
        int answer = 0;
        int n = piles.size();
        for (int i = 0; i < n; ++i) {
            int cntPile = piles[i];
            int cntH = cntPile / k;
            int d = cntPile % k == 0 ? 0 : 1;
            cntH += d;
            answer += cntH;
            if (answer > h) {
                break;
            }
        }

        return answer;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int answer;
        int maxK = *max_element(piles.begin(), piles.end());
        int minK = 1;
        int left = minK;
        int right = maxK;
        int mid;
        int cntH;
        while (left < right) {
            mid = left + (right - left) / 2;
            cntH = check(piles, h, mid);
            if (cntH <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        answer = left;

        return answer;
    }
};

int main() {
    vector<int> piles;
    int h;
    int answer;
    Solution solve;

    piles = {3, 6, 7, 11}, h = 8;
    answer = 4;
    assert(answer == solve.minEatingSpeed(piles, h));

    piles = {30, 11, 23, 4, 20}, h = 6;
    answer = 23;
    assert(answer == solve.minEatingSpeed(piles, h));

    piles = {30, 11, 23, 4, 20}, h = 5;
    answer = 30;
    assert(answer == solve.minEatingSpeed(piles, h));

    piles = {312884470}, h = 312884469;
    answer = 2;
    assert(answer == solve.minEatingSpeed(piles, h));

    return 0;
}

