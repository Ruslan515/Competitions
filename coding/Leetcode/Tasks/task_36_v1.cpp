// https://leetcode.com/problems/valid-sudoku/
// Created by ruslan515 on 21.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int n = board.size();
        bool answer = false;

        for (int i = 0; i < n; ++i) {
            set<int> set_d;
            for (int j = 0; j < n; ++j) {
                char temp = board[i][j];
                if (temp != '.') {
                    if (set_d.count(temp) != 0) {
                        return answer;
                    } else {
                        set_d.insert(temp);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            set<int> set_d;
            for (int j = 0; j < n; ++j) {
                char temp = board[j][i];
                if (temp != '.') {
                    if (set_d.count(temp) != 0) {
                        return answer;
                    } else {
                        set_d.insert(temp);
                    }
                }
            }
        }

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                set<int> set_d;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        char temp = board[i + x][j + y];
                        if (temp != '.') {
                            if (set_d.count(temp) != 0) {
                                return answer;
                            } else {
                                set_d.insert(temp);
                            }
                        }

                    }
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board;
    bool answer;
    Solution solve;

    board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    answer = true;
    assert(solve.isValidSudoku(board) == answer);

    board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    answer = false;
    assert(solve.isValidSudoku(board) == answer);

    return 0;
}