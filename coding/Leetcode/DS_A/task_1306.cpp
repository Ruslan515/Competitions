// https://leetcode.com/problems/jump-game-iii/description/
// Created by ruslan515 on 05.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int TARGET = 0;
    bool canReach(vector<int> &arr, int start) {
        bool answer = false;
        int n = arr.size();
        queue<int> q;
        set<int> visited;
        q.push(start);
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                int current = q.front();
                q.pop();
                int diff = arr[current];
                if (diff == TARGET) {
                    answer = true;
                    return answer;
                }
                visited.insert(current);
                int next;
                for (int j = -1; j <= 1; j += 2) {
                    next = current + j * diff;
                    bool checkOutside = (next >= 0) && (next < n);
                    if (checkOutside && visited.find(next) == visited.end()) {
                        q.push(next);
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> arr;
    int start;
    bool answer;
    Solution solve;

    arr = {4, 2, 3, 0, 3, 1, 2}, start = 5;
    answer = true;
    assert(answer == solve.canReach(arr, start));

    arr = {4, 2, 3, 0, 3, 1, 2}, start = 0;
    answer = true;
    assert(answer == solve.canReach(arr, start));

    arr = {3, 0, 2, 1, 2}, start = 2;
    answer = false;
    assert(answer == solve.canReach(arr, start));

    return 0;
}