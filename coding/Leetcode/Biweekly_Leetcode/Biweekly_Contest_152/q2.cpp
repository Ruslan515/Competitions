//
// Created by omega515 on 15.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;

        return answer;
    }
};

int main() {
    vector<int> nums;
    vector<int> answer;
    Solution solve;

    nums = {4, 3, 2, 1};
    answer = {0, 0, 1, 1};
    assert(answer == solve.transformArray(nums));

    return 0;
}
