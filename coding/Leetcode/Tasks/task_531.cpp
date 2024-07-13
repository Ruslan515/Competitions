// https://leetcode.com/problems/lonely-pixel-i/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 11.07.24.
//


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findLonelyPixel(vector<vector<char>> &picture) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int m = picture.size();
        int n = picture[0].size();
        unordered_map<int, int> rows, cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (picture[i][j] == 'B') {
                    ++cols[j];
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<char>> picture;
    int answer;
    Solution solve;

    picture = {{'W', 'W', 'B'},
               {'W', 'B', 'W'},
               {'B', 'W', 'W'}};
    answer = 3;
    assert(answer == solve.findLonelyPixel(picture));

    picture = {{'B', 'B', 'B'},
               {'B', 'B', 'W'},
               {'B', 'B', 'B'}};
    answer = 0;
    assert(answer == solve.findLonelyPixel(picture));

    return 0;
}
