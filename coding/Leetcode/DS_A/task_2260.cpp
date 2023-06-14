// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
// Created by ruslan515 on 14.06.23.
//

#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

class Solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        int n = cards.size();
        int left = 0;
        int right = 0;
        int answer = INF;
        unordered_map<int, int> mp;
        for (; right < n; ++right) {
            while (right < n && mp.count(cards[right]) == 0) {
                ++mp[cards[right]];
                ++right;
            }
            if (right == n) {
                break;
            }

            int key = cards[right];
            ++mp[key];

            while (left < n && cards[left] != key) {
                mp.erase(cards[left]);
                ++left;
            }
            --mp[key];
            answer = min(answer, right - left + 1);
            ++left;
        }
        if (answer == INF) {
            answer = -1;
        }

        return answer;
    }
};

int main() {
    vector<int> cards;
    int answer;
    Solution solve;

    cards = {70, 37, 70, 41, 1, 62, 71, 49, 38, 50, 29, 76, 29, 41, 22, 66, 88, 18, 85, 53};
    answer = 3;
    assert(answer == solve.minimumCardPickup(cards));

    cards = {95, 11, 8, 65, 5, 86, 30, 27, 30, 73, 15, 91, 30, 7, 37, 26, 55, 76, 60, 43, 36, 85, 47, 96, 6};
    answer = 3;
    assert(answer == solve.minimumCardPickup(cards));

    cards = {1, 0, 5, 3};
    answer = -1;
    assert(answer == solve.minimumCardPickup(cards));

    cards = {3, 4, 2, 3, 4, 7};
    answer = 4;
    assert(answer == solve.minimumCardPickup(cards));

    return 0;
}
