// https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17
// Created by omega515 on 17.02.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void backtrack(int i, string curr, string tiles, int &answer, unordered_set<string> &uniqueStr) {
        int n = tiles.size();
        if (i > n) {
            return;
        }

        for (int j = i; j < n; ++j) {
            curr.push_back(tiles[j]);
            if (uniqueStr.find(curr) == uniqueStr.end()) {
                ++answer;
                uniqueStr.insert(curr);
                backtrack(j + 1, curr, tiles, answer, uniqueStr);
            }
            curr.pop_back();
        }

    }

    int numTilePossibilities(string tiles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        string curr = "";
        unordered_set<string> uniqueStr;
        backtrack(0, curr, tiles, answer, uniqueStr);

        return answer - 1;
    }
};

int main() {
    string tiles;
    int answer;
    Solution solve;

    tiles = "AAB";
    answer = 8;
    assert(answer == solve.numTilePossibilities(tiles));

    tiles = "AAABBC";
    answer = 188;
    assert(answer == solve.numTilePossibilities(tiles));

    tiles = "V";
    answer = 1;
    assert(answer == solve.numTilePossibilities(tiles));

    return 0;
}
