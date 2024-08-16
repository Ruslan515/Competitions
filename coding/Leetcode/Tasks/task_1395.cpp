// https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29
// Created by omega515 on 29.07.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTeams(vector<int> &rating) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int n = rating.size();
        int ri, rj, rk;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ri = rating[i];
                    rj = rating[j];
                    rk = rating[k];
                    bool x = ri < rj && rj < rk;
                    bool y = ri > rj && rj > rk;
                    if (x || y) {
                        ++answer;
                    }
                }
            }
        }

        return answer;
    }
};


int main() {
    vector<int> rating;
    int answer;
    Solution solve;

    rating = {2, 5, 3, 4, 1};
    answer = 3;
    assert(answer == solve.numTeams(rating));

    rating = {2, 1, 3};
    answer = 0;
    assert(answer == solve.numTeams(rating));

    rating = {1, 2, 3, 4};
    answer = 4;
    assert(answer == solve.numTeams(rating));

    return 0;
}
