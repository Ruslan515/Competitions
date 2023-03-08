// https://leetcode.com/problems/koko-eating-bananas/
// Created by ruslan515 on 08.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaxPile(vector<int> &piles) {
        int maxPiles = piles[0];
        int n = piles.size();
        for(int i = 1; i < n; ++i) {
            maxPiles = max(maxPiles, piles[i]);
        }
        return maxPiles;
    }

    long long  getHour(vector<int> &piles, int k) {
        long long h = 0;
        int n = piles.size();
        int pile;
        for (int i = 0; i < n; ++i) {
            pile = piles[i];
            int d = pile / k;
            int remains = pile % k;
            if (remains > 0) {
                ++d;
            }
            h += d;
        }
        return h;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        int n = piles.size();
        if (n == 1) {
            int k = piles[0] / h;
            int remains = piles[0] % h;
            if (remains != 0) {
                ++k;
            }
            return k;
        }

        int maxK  = getMaxPile(piles);

        int minK = 1;
        int midK;
        long long currHour;

        while (minK <= maxK) {
            midK = minK + (maxK - minK) / 2;
            currHour = getHour(piles, midK);
            if (currHour == h) {
                break;
            }
            if (currHour > h) {
                minK = midK + 1;
            } else {
                maxK = midK - 1;
            }
        }
        while (currHour <= h) {
            --midK;
            currHour = getHour(piles, midK);
        }

        int answer = ++midK;

        return answer;
    }
};

void read_data(vector<int> &piles, int &h) {
    cin >> h;
    int t;
    while (cin >> t)
        piles.push_back(t);
    return;
}

int main() {
    vector<int> piles;
    int h;
    read_data(piles, h);
    Solution solve;
    cout << solve.minEatingSpeed(piles, h);
    return 0;
}