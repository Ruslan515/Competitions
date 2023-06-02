// https://leetcode.com/problems/design-tic-tac-toe/
// Created by ruslan515 on 31.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    map<int, int> players = {{1, 'X'},
                             {2, '0'}};
public:
    TicTacToe(int n) {
        for (int i = 0; i < n; ++i) {
            vector<char> temp(n, 'Q');
            board.push_back(temp);
        }
    }

    int move(int row, int col, int player) {
        char symbol = players[player];
        board[row][col] = symbol;
        int n = board.size();

        // check row
        if (board[row][0] == symbol) {
            int i = 1;
            for (; i < n; ++i) {
                if (board[row][i - 1] != board[row][i]) {
                    break;
                }
            }
            if (i == n) {
                return player;
            }
        }

        // check col
        if (board[0][col] == symbol) {
            int i = 1;
            for (; i < n; ++i) {
                if (board[i - 1][col] != board[i][col]) {
                    break;
                }
            }
            if (i == n) {
                return player;
            }
        }

        // check diag
        if (col == row) {
            if (board[0][0] == symbol) {
                int i = 1;
                for (; i < n; ++i) {
                    if (board[i - 1][i - 1] != board[i][i]) {
                        break;
                    }
                }
                if (i == n) {
                    return player;
                }
            }
        }

        // check subdiag
        if (col + row == n - 1) {
            if (board[0][n - 1] == symbol) {
                int i = 1;
                for (; i < n; ++i) {
                    int j = n - i - 1;
                    if (board[i - 1][j + 1] != board[i][j]) {
                        break;
                    }
                }
                if (i == n) {
                    return player;
                }
            }
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main() {
    TicTacToe *ticTacToe = new TicTacToe(2);
    assert(0 == ticTacToe->move(0, 0, 2));
    assert(0 == ticTacToe->move(1, 1, 1));
    assert(2 == ticTacToe->move(0, 1, 2));


//    TicTacToe *ticTacToe = new TicTacToe(3);
//    assert(0 == ticTacToe->move(0, 0, 1));
//    assert(0 == ticTacToe->move(0, 2, 2));
//    assert(0 == ticTacToe->move(2, 2, 1));
//    assert(0 == ticTacToe->move(1, 1, 2));
//    assert(0 == ticTacToe->move(2, 0, 1));
//    assert(0 == ticTacToe->move(1, 0, 2));
//    assert(1 == ticTacToe->move(2, 1, 1));

    return 0;
}