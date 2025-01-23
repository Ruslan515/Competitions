// https://leetcode.com/contest/weekly-contest-388/problems/apple-redistribution-into-boxes/
// Created by omega515 on 03.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
        int answer = 0;
        int sums = 0;
        int n = apple.size(), m = capacity.size();
        for (int i = 0; i < n; ++i) {
            sums += apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        int j = 0;
        while (j < m && sums > 0) {
            sums -= capacity[j];
            ++j;
        }
        answer = j;

        return answer;
    }
};

int main() {
    vector<int> apple, capacity;
    int answer;
    Solution solve;

    apple = {1, 3, 2}, capacity = {4, 3, 1, 5, 2};
    answer = 2;
    assert(answer == solve.minimumBoxes(apple, capacity));

    apple = {5, 5, 5}, capacity = {2, 4, 2, 7};
    answer = 4;
    assert(answer == solve.minimumBoxes(apple, capacity));
    return 0;
}

