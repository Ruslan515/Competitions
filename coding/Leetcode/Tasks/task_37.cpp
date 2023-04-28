// https://leetcode.com/problems/sudoku-solver/description/
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

    void backtrack(vector<vector<char>> &board, int n, vector<pair<int, int>> &matrix) {
        int size = matrix.size();
        if (size == 9 * 9) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << i << " " << j << "\n";
                matrix.push_back(make_pair(i, j));
                char temp = board[i][j];
                if (temp == '.') {
                    for (int x = 1; x < 10; ++x) {
                        board[i][j] = x + '0';
                        bool check = isValidSudoku(board);
                        if (check) {
                            backtrack(board, n, matrix);
                        }
                        board[i][j] = '.';
                    }
                }
                matrix.pop_back();
            }
        }
    }

    void solveSudoku(vector<vector<char>> &board) {
        int n = board.size();
        vector<pair<int, int>> matrix;
        backtrack(board, n, matrix);
    }

};

int main() {
    vector<vector<char>> board;
    vector<vector<char>> answer;
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
    answer = {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
              {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
              {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
              {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
              {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
              {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
              {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
              {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
              {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    solve.solveSudoku(board);
    assert(board == answer);


    return 0;
}