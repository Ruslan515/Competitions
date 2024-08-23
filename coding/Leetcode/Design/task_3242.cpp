// https://leetcode.com/problems/design-neighbor-sum-service/description/
// Created by omega515 on 21.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class NeighborSum {
private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> coord;
    int n;
    vector<pair<int, int>> adj = {
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0}
    };
    vector<pair<int, int>> diag = {
            {1,  1},
            {-1, -1},
            {1,  -1},
            {-1, 1}
    };

    int getSums(int value, vector<pair<int, int>> &diff) {
        auto [y, x] = coord[value];
        int answer = 0;
        int newX, newY;
        bool checkX, checkY;
        for (pair<int, int> p: diff) {
            auto [diffY, diffX] = p;
            newX = x + diffX;
            newY = y + diffY;
            checkX = (newX < this->n) && (newX >= 0);
            checkY = (newY < this->n) && (newY >= 0);
            if (checkX && checkY) {
                answer += this->grid[newY][newX];
            }
        }

        return answer;
    }

public:
    NeighborSum(vector<vector<int>> &grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        this->grid = grid;
        this->n = grid.size();
        int val;
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->n; ++j) {
                val = grid[i][j];
                coord[val] = {i, j};
            }
        }
    }


    int adjacentSum(int value) {
        int answer = this->getSums(value, this->adj);
        return answer;
    }

    int diagonalSum(int value) {
        int answer = this->getSums(value, this->diag);
        return answer;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main() {
    vector<vector<int>> grid;

//    grid = {{1,  2,  0,  3},
//            {4,  7,  15, 6},
//            {8,  9,  10, 11},
//            {12, 13, 14, 5}};
//    NeighborSum *obj = new NeighborSum(grid);
//    obj = new NeighborSum(grid);
//    assert(23 == obj->adjacentSum(15));
//    assert(45 == obj->diagonalSum(9));


    grid = {{0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}};
    NeighborSum *obj = new NeighborSum(grid);
    assert(6 == obj->adjacentSum(1));
    assert(16 == obj->adjacentSum(4));
    assert(16 == obj->diagonalSum(4));
    assert(4 == obj->diagonalSum(8));

    return 0;
}

