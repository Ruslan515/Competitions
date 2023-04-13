// https://leetcode.com/problems/n-queens/
// Created by ruslan515 on 13.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool tryQueen(vector<vector<int>> &board, int n, int row, int col) {
        bool answer = false;
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 1) {
                return answer;
            }
        }

        for (int i = 1; i <= row && col - i >= 0; ++i) {
            if (board[row - i][col - i] == 1) {
                return answer;
            }
        }

        for (int i = 1; i <= row && col + i < n; ++i) {
            if (board[row - i][col + i] == 1) {
                return answer;
            }
        }
        answer = true;
        return answer;
    }

    vector<string> getBoard(vector<vector<int>> &board, int n) {
        map<int, char> mp = {{0, '.'}, {1, 'Q'}};
        string temp;
        vector<string> answer;
        for (int i = 0; i < n; ++i) {
            temp = "";
            for (int j = 0; j < n; ++j) {
                temp += mp[board[i][j]];
            }
            answer.push_back(temp);
        }
        return answer;
    }

    void printBoard(vector<vector<int>> &board, int n) {
        map<int, char> mp = {{0, '.'}, {1, 'Q'}};
        char temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp = mp[board[i][j]];
                cout << temp << " ";
            }
            cout << "\n";
        }
        for (int i = 0; i < n; ++i) {
            cout << "==";
        }
        cout << "\n";
        return;
    }
    void setQueen(vector<vector<string>> &answer, vector<vector<int>> &board, int n, int col) {
        if (col == n) {
            vector<string> sub_answer = getBoard(board, n);
            answer.push_back(sub_answer);
            return;
        }
        for (int row = 0; row < n; ++row) {
            if (tryQueen(board, n, col, row)) {
                board[col][row] = 1;
//                printBoard(board, n);
                setQueen(answer, board, n, col + 1);
//                printBoard(board, n);
                board[col][row] = 0;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> answer;
        setQueen(answer, board, n, 0);
        return answer;
    }
};

int main() {
    int n;
    vector<vector<string>> answer;
    Solution solve;

    n = 4;
    answer = {{".Q..", "...Q", "Q...", "..Q."},
              {"..Q.", "Q...", "...Q", ".Q.."}};
    assert(solve.solveNQueens(n) == answer);

    n = 1;
    answer = {{"Q"}};
    assert(solve.solveNQueens(n) == answer);

    return 0;
}