// https://leetcode.com/problems/path-crossing/
// Created by ruslan515 on 19.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        map<char, pair<int, int>> mp = {
                {'N', {0,  1}},
                {'S', {0,  -1}},
                {'E', {1,  0}},
                {'W', {-1, 0}},
        };

        int x = 0;
        int y = 0;
        st.insert(make_pair(x, y));
        int dx, dy;
        bool answer = false;
        for (char ch: path) {
            pair<int, int> dxdy = mp[ch];
            dx = dxdy.first;
            dy = dxdy.second;
            x += dx;
            y += dy;
            pair<int, int> curr = {x, y};
            if (st.find(curr) != st.end()) {
                answer = true;
                break;
            }
            st.insert(curr);
        }

        return answer;
    }
};

int main() {
    string path;
    bool answer;
    Solution solve;

    path = "NNSWWEWSSESSWENNW";
    answer = true;
    assert(answer == solve.isPathCrossing(path));

    path = "NES";
    answer = false;
    assert(answer == solve.isPathCrossing(path));

    path = "NESWW";
    answer = true;
    assert(answer == solve.isPathCrossing(path));

    return 0;
}
