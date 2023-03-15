// https://leetcode.com/problems/kth-missing-positive-number/
// Created by ruslan515 on 06.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        int answer = 1;
        set<string> set_deadends;

        for (string dead: deadends) {
            set_deadends.insert(dead);
        }

        set<string> used;
        if (set_deadends.count("0000")) {
            return -1;
        }
        if ("0000" == target) {
            return 0;
        }
        used.insert("0000");
        queue<string> q;
        q.push("0000");
        while (!q.empty() && used.size() < 10000) {
            int size_queue = q.size();
            for (int idx = 0; idx < size_queue; ++idx) {
                string current = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    for(int step = -1; step <= 1; step += 2) {
                        int x;
                        x = current[i] - '0';
                        x += step;
                        if (x == -1) {
                            x = 9;
                        }
                        if (x == 10) {
                            x = 0;
                        }
                        char y = x + '0';
                        string temp = current;
                        temp[i] = y;
                        if (temp == target) {
                            return answer;
                        }
                        if (set_deadends.count(temp) == 0) {
                            if (used.count(temp) == 0) {
                                used.insert(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            ++answer;
        }
        return -1;
    }
};

void read_data(vector<string> &deadends, string &target) {
    cin >> target;
    string t;
    while (cin >> t)
        deadends.push_back(t);
    return;
}

int main() {
    vector<string> deadends;
    string target;
    read_data(deadends, target);
    Solution solve;
    cout << solve.openLock(deadends, target);

    return 0;
}
