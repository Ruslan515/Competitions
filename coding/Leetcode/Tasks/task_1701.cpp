// https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
// Created by omega515 on 09.07.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        double answer = 0.0;
        int n = customers.size();
        int arrival, end, time, diff;
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            arrival = customers[i][0];
            time = customers[i][1];
            if (prev > arrival) {
                diff = prev - arrival;
                answer += diff + time;
                prev = prev + time;
            } else {
                answer += time;
                prev = arrival + time;
            }

        }
        answer = 1.0 * answer / n;


        return answer;
    }
};

int main() {
    vector<vector<int>> customers;
    double answer;
    Solution solve;

    customers = {{1, 2},
                 {2, 5},
                 {4, 3}};
    answer = 5.00000;
    assert(answer == solve.averageWaitingTime(customers));

    customers = {{5,  2},
                 {5,  4},
                 {10, 3},
                 {20, 1}};
    answer = 3.25000;
    assert(answer == solve.averageWaitingTime(customers));

    return 0;
}
