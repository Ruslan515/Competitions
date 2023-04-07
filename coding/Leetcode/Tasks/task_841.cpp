// https://leetcode.com/problems/keys-and-rooms/description/
// Created by ruslan515 on 07.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int v, vector<bool> &used, vector<vector<int>> &rooms) {
        used[v] = true;
        for (int i = 0; i < rooms[v].size(); ++i) {
            int to = rooms[v][i];
            if(!used[to]) {
                dfs(to, used, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();
        vector<bool> used(n, false);
        dfs(0, used, rooms);
        bool answer = true;
        for (bool x: used) {
            if (x == false) {
                answer = false;
                break;
            }
        }
        return answer;
    }
};

void read_data(vector<vector<int>> &rooms) {
    int m, n;
    cin >> m >> n;
    int a;
    for (int i = 0; i < m; ++i) {
        vector<int> t;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            t.push_back(a);
        }
        rooms.push_back(t);
    }
    return;
}

int main() {
    vector<vector<int>> rooms;
//    read_data(rooms);
//    for (int i = 0; i < rooms.size(); ++i) {
//        for (int j = 0; j < rooms{0}.size(); ++j) {
//            cout << rooms{i}{j} << ", ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    Solution solve;
    rooms = {{1},
             {2},
             {3},
             {}};
    assert(solve.canVisitAllRooms(rooms) == true);

    rooms = {{1, 3},
             {3, 0, 1},
             {2},
             {0}};
    cout << solve.canVisitAllRooms(rooms) << "\n";
    assert(solve.canVisitAllRooms(rooms) == false);

    return 0;
}