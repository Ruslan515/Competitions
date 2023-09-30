// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
// Created by ruslan515 on 29.09.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> diff = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1},
    };

    bool check(int x, int y, int n, int m) {
        bool ans = (x >= 0 && x < n) && (y >= 0 && y < m);
        return ans;
    }

    set<pair<int, int>> createSet(vector<vector<char>> &maze, vector<int> &entrance) {
        int m = maze.size();
        int n = maze[0].size();
        set<pair<int, int>> setExit;
        pair<int, int> entr;
        entr.first = entrance[1];
        entr.second = entrance[0];
        if (n == 1) {
            for (int i = 0; i < m; ++i) {
                pair<int, int> yx = make_pair(i, 0);
                if (yx != entr && maze[i][0] == '.') {
                    setExit.insert(yx);
                }
            }
            return setExit;
        }

        if (m == 1) {
            for (int j = 0; j < n; ++j) {
                pair<int, int> yx = make_pair(0, j);
                if (yx != entr && maze[0][j] == '.') {
                    setExit.insert(yx);
                }
            }
            return setExit;
        }

        for (int j = 0; j < n; j += n - 1) {
            for (int i = 0; i < m; ++i) {
                pair<int, int> yx = make_pair(i, j);
                if (yx != entr && maze[i][j] == '.') {
                    setExit.insert(yx);
                }
            }
        }
        for (int i = 0; i < m; i += m - 1) {
            for (int j = 1; j < n - 1; ++j) {
                pair<int, int> yx = make_pair(i, j);
                if (yx != entr && maze[i][j] == '.') {
                    setExit.insert(yx);
                }
            }
        }

        return setExit;
    }


    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int answer = -1;
        set<pair<int, int>> setExit = createSet(maze, entrance);
        if (setExit.size() == 0) {
            return answer;
        }

        set<pair<int, int>> visited;
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});

        while (!q.empty()) {
            int size_q = q.size();
            vector<int> current;
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                int x, y, dist;
                y = current[0];
                x = current[1];
                dist = current[2];
                visited.insert(make_pair(y, x));
                int newX, newY;
                for (auto dxy: diff) {
                    auto [dy, dx] = dxy;
                    newX = x + dx;
                    newY = y + dy;
                    pair<int, int> newXY = {newY, newX};
                    if (visited.find(newXY) != visited.end()) {
                        continue;
                    }
                    if (setExit.find(newXY) != setExit.end()) {
                        answer = dist + 1;
                        return answer;
                    }
                    bool ch = check(newX, newY, n, m);
                    if (ch) {
                        char val = maze[newY][newX];
                        if (val == '.') {
                            q.push({newY, newX, dist + 1});
                        }
                    }

                }

            }
        }


        return answer;
    }
};

int main() {
    vector<vector<char>> maze;
    vector<int> entrance;
    int answer;
    Solution solve;

    maze = {{'.', '.', '+'}};
    entrance = {0, 0};
    answer = 1;
    assert(answer == solve.nearestExit(maze, entrance));

    maze = {{'+', '+', '.', '+'},
            {'.', '.', '.', '+'},
            {'+', '+', '+', '.'}};
    entrance = {1, 2};
    answer = 1;
    assert(answer == solve.nearestExit(maze, entrance));

    maze = {{'+', '+', '+', '+'},
            {'.', '.', '.', '+'},
            {'+', '.', '.', '+'},
            {'+', '.', '+', '.'}};
    entrance = {1, 2};
    answer = 2;
    assert(answer == solve.nearestExit(maze, entrance));

    maze = {{'+', '+', '+', '+'},
            {'.', '+', '.', '+'},
            {'+', '+', '+', '.'}};
    entrance = {1, 2};
    answer = -1;
    assert(answer == solve.nearestExit(maze, entrance));

    maze = {{'+', '+', '+'},
            {'.', '.', '.'},
            {'+', '+', '+'}}, entrance = {1, 0};
    answer = 2;
    assert(answer == solve.nearestExit(maze, entrance));

    maze = {{'.', '+'}}, entrance = {0, 0};
    answer = -1;
    assert(answer == solve.nearestExit(maze, entrance));

    return 0;
}