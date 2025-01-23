// https://leetcode.com/contest/biweekly-contest-140/problems/maximize-the-total-height-of-unique-towers/description/
// Created by omega515 on 28.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getFirstN(int n) {
        long long answer = 0;
        answer = (long long) ((1 + (long long)n) * (long long)n / 2);

        return answer;
    }

    long long getSums(vector<int> &maximumHeight) {
        long long answer = 0;
        for (int num: maximumHeight) {
            answer += (long long) num;
        }
        return answer;
    }

    long long maximumTotalSum(vector<int> &maximumHeight) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long answer = -1;
        int n = maximumHeight.size();
        long long firstSums = getFirstN(n);
        long long currentSums = getSums(maximumHeight);
        if (currentSums < firstSums) {
            return answer;
        }
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        answer = (long long) maximumHeight[0];
        int prev = maximumHeight[0], current;
        for (int i = 1; i < n; ++i) {
            current = maximumHeight[i];
            if (current == prev) {
                --current;
            } else if (current > prev) {
                current = prev - 1;
            }
            if (current == 0) {
                return -1;
            }
            maximumHeight[i] = current;
            answer += (long long) current;
            prev = current;
        }

        return answer;
    }
};

int main() {
    vector<int> maximumHeight;
    long long answer;
    Solution solve;

    long long x = (long long)52290 * (long long)52289;

    maximumHeight = {6,6,6,3,7,2,6,5};
    answer = -1;
    assert(answer == solve.maximumTotalSum(maximumHeight));

    maximumHeight = {5, 5, 5};
    answer = 12;
    assert(answer == solve.maximumTotalSum(maximumHeight));

    maximumHeight = {2, 3, 4, 3};
    answer = 10;
    assert(answer == solve.maximumTotalSum(maximumHeight));

    maximumHeight = {15, 10};
    answer = 25;
    assert(answer == solve.maximumTotalSum(maximumHeight));

    maximumHeight = {2, 2, 1};
    answer = -1;
    assert(answer == solve.maximumTotalSum(maximumHeight));

    return 0;
}
