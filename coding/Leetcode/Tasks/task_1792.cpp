// https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15
// Created by omega515 on 15.12.24.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<double, pair<int, int>> pr;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        double answer = 0;
        priority_queue<pr> priorityQueue;
        int n = classes.size();
        int pass, total;
        double ratio, deltaRatio;
        for (auto cls: classes) {
            pass = cls[0];
            total = cls[1];
            ratio = (double) pass / total;
            deltaRatio = (double(pass + 1) / (total + 1)) - ratio;
            priorityQueue.push({deltaRatio, {pass, total}});
        }
        pr item;
        for (int i = 0; i < extraStudents; ++i) {
            item = priorityQueue.top();
            priorityQueue.pop();
            pass = item.second.first + 1;
            total = item.second.second + 1;
            ratio = (double) pass / total;
            deltaRatio = (double(pass + 1) / (total + 1)) - ratio;
            priorityQueue.push({deltaRatio, {pass, total}});
        }
        while (!priorityQueue.empty()) {
            item = priorityQueue.top();
            priorityQueue.pop();
            pass = item.second.first;
            total = item.second.second;
            ratio = (double) pass / total;
            answer += ratio;
        }
        answer /= n;

        return answer;
    }
};


int main() {
    vector<vector<int>> classes;
    int extraStudents;
    double answer;
    Solution solve;

    classes = {{1, 2},
               {3, 5},
               {2, 2}}, extraStudents = 2;
    answer = 0.78333;
    assert(answer == solve.maxAverageRatio(classes, extraStudents));

    classes = {{2, 4},
               {3, 9},
               {4, 5},
               {2, 10}}, extraStudents = 4;
    answer = 0.53485;
    assert(answer == solve.maxAverageRatio(classes, extraStudents));

    return 0;
}
