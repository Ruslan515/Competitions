// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Created by ruslan515 on 15.01.23.
//

#include <string>
#include <vector>

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string op: operations) {
            if (op == "++X" || op == "X++")
                ans++;
            else
                ans--;
        }
        return ans;
    }
};