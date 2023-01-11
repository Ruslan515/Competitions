//
// https://leetcode.com/problems/paint-fence/
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp(n + 1);
        dp[0] = k;
        dp[1] = k * k;

        for (int i = 2; i < n; ++i) {
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
        }
        return dp[n- 1];
    }
};

void read_data(int& n, int& k) {
    std::cin >> n >> k;
    return;
}

int main() {
    int n, k;
    read_data(n, k);
    Solution solve;
    std::cout << solve.numWays(n, k);
    return 0;
}