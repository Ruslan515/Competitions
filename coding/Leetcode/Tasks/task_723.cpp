// https://leetcode.com/problems/candy-crush/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 01.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> findSameType(vector<int> &v) {
        vector<pair<int, int>> answer;
        int size = v.size();
        for (int i = 0; i < size - 2; ++i) {
            int start, end;
            if (v[i] != 0) {
                if (v[i] == v[i + 1] && v[i + 1] == v[i + 2]) {
                    start = i;
                    while (i < size && v[i] == v[i + 1]) {
                        ++i;
                    }
                    end = i;
                    answer.push_back({start, end});
                }
            }
        }

        return answer;
    }

    void gravity(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();

        for (int j = 0; j < n; ++j) {
            int i = m - 1;
            int start, end;
            while (i >= 0) {
                if (board[i][j] == -1) {
                    start = i;
                    while (i >= 0 && board[i][j] == -1) {
                        --i;
                    }
                    end = i;
                    int diff = start - end;
                    for (int k = end; k >= 0; --k) {
                        board[k + diff][j] = board[k][j];
                    }
                    for (int k = 0; k < diff; ++k) {
                        board[k][j] = 0;
                    }
                    i = end;
                    continue;

                }
                --i;
            }
        }

    }

    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> answer;
        int m = board.size();
        int n = board[0].size();
        while (true) {
            vector<vector<pair<int, int>>> rows;
            int maxLenRows = 0;
            for (int i = 0; i < m; ++i) {
                vector<pair<int, int>> pairs = this->findSameType(board[i]);
                int size = pairs.size();
                maxLenRows = max(maxLenRows, size);
                rows.push_back(pairs);
            }

            vector<vector<pair<int, int>>> cols;
            int maxLenCols = 0;
            for (int j = 0; j < n; ++j) {
                vector<int> tmp;
                for (int i = 0; i < m; ++i) {
                    tmp.push_back(board[i][j]);
                }
                vector<pair<int, int>> pairs = this->findSameType(tmp);
                int size = pairs.size();
                maxLenCols = max(maxLenCols, size);
                cols.push_back(pairs);
            }
            if (maxLenCols == 0 && maxLenRows == 0) {
                break;
            }
            int start, end;
            for (int i = 0; i < m; ++i) {
                vector<pair<int, int>> v = rows[i];
                for (pair<int, int> p: v) {
                    start = p.first;
                    end = p.second;
                    for (int j = start; j <= end; ++j) {
                        board[i][j] = -1;
                    }
                }
            }

            for (int j = 0; j < n; ++j) {
                vector<pair<int, int>> v = cols[j];
                for (pair<int, int> p: v) {
                    start = p.first;
                    end = p.second;
                    for (int i = start; i <= end; ++i) {
                        board[i][j] = -1;
                    }
                }
            }
            this->gravity(board);

        }


        answer = board;
        return answer;
    }
};


int main() {
    vector<vector<int>> board;
    vector<vector<int>> answer;
    Solution solve;

    board = {{5, 5, 5, 3, 2},
             {3, 4, 3, 2, 4},
             {3, 2, 3, 4, 2},
             {1, 1, 2, 3, 1},
             {5, 3, 4, 4, 3}};
    answer = {{0, 0, 0, 3, 2},
              {3, 4, 3, 2, 4},
              {3, 2, 3, 4, 2},
              {1, 1, 2, 3, 1},
              {5, 3, 4, 4, 3}};
    assert(answer == solve.candyCrush(board));


    board = {{110, 5,   112, 113, 114},
             {210, 211, 5,   213, 214},
             {310, 311, 3,   313, 314},
             {410, 411, 412, 5,   414},
             {5,   1,   512, 3,   3},
             {610, 4,   1,   613, 614},
             {710, 1,   2,   713, 714},
             {810, 1,   2,   1,   1},
             {1,   1,   2,   2,   2},
             {4,   1,   4,   4,   1014}};
    answer = {{0,   0,   0,   0,   0},
              {0,   0,   0,   0,   0},
              {0,   0,   0,   0,   0},
              {110, 0,   0,   0,   114},
              {210, 0,   0,   0,   214},
              {310, 0,   0,   113, 314},
              {410, 0,   0,   213, 414},
              {610, 211, 112, 313, 614},
              {710, 311, 412, 613, 714},
              {810, 411, 512, 713, 1014}};
    assert(answer == solve.candyCrush(board));


    return 0;
}
