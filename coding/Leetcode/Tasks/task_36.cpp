// https://leetcode.com/problems/valid-sudoku/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 21.01.23.
//

#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int size = 9;
    bool isValidSudoku(vector<vector<char>>& board) {
        bool answer = true;

        for (int i = 0; i < size; ++i) {
            set<char> st;
            for (int j = 0; j < size; ++j) {
                char temp = board[i][j];
                if (temp != '.') {
                    if (st.count(temp) == 1) {
                        answer = false;
                        return answer;
                    } else {
                        st.insert(temp);
                    }
                }

            }
        }

        for (int j = 0; j < size; ++j) {
            set<char> st;
            for (int i = 0; i < size; ++i) {
                char temp = board[i][j];
                if (temp != '.') {
                    if (st.count(temp) == 1) {
                        answer = false;
                        return answer;
                    } else {
                        st.insert(temp);
                    }
                }

            }
        }

        for(int i = 0; i < size; i += 3) {
            for(int j = 0; j < size; j += 3) {
                set<char> st;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        char temp = board[i + x][j + y];
                        if (temp != '.') {
                            if (st.count(temp) == 1) {
                                answer = false;
                                return answer;
                            }
                            else {
                                st.insert(temp);
                            }
                        }
                    }
                }
            }
        }

        return answer;
    }
};

void read_data(vector<vector<char>>& board) {
    char temp;
    for(int i = 0; i < 9; ++i) {
        vector<char> v;
        for (int j = 0; j < 9; ++j) {
            cin >> temp;
            v.push_back(temp);
        }
    }
    return;
}

int main() {
    vector<vector<char>> board;
    read_data(board);
    Solution solve;

    cout << solve.isValidSudoku(board);

    return 0;
}