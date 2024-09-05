// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02
// Created by omega515 on 02.09.24.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int answer = 0;
        int i = 0;
        int n = chalk.size();
        int current, w;
        while (k >= 0) {
            current = i % n;
            w = chalk[current];
            k -= w;

            ++i;
        }
        answer = current;

        return answer;
    }
};

int main() {
    vector<int> chalk;
    int k;
    int answer;
    Solution solve;

    chalk = {5, 1, 5}, k = 22;
    answer = 0;
    assert(answer == solve.chalkReplacer(chalk, k));

    chalk = {3, 4, 1, 2}, k = 25;
    answer = 1;
    assert(answer == solve.chalkReplacer(chalk, k));

    return 0;
}
