//
// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ans = 0;
        int n = cost.size();
        int one = 0;
        int two = 0;
        int current = 0;
        for (int i = n - 1; i >= 0; --i) {
            current = cost[i] + min(one, two);
            two = one;
            one = current;
        }
        ans = min(current, two);
        return ans;
    }
};

void read_data(vector<vector<char>>& cost) {
    int n, m;
    std::cin >> m >> n;
    cost.resize(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char temp;
            std::cin >> temp;
            cost[i].push_back(temp);
        }
    }

    return;
}

int main() {
    vector<vector<char>> cost;
    read_data(cost);
    Solution s;
    std::cout << s.minCostClimbingStairs(cost);
    return 0;
}