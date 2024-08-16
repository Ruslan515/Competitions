// https://leetcode.com/problems/armstrong-number/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 24.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n_copy = n;
        bool answer = false;
        int k;
        vector<int> v;
        int t = 10;
        while (n) {
            int d = n % t;
            v.push_back(d);
            n /= t;
        }
        k = v.size();
        int sums = 0;
        for (int i = 0; i < k; ++i) {
            sums += pow(v[i], k);
        }
        if (sums == n_copy) {
            answer = true;
        }

        return answer;
    }
};

int main() {
    int n;
    bool answer;
    Solution solve;

    n = 153;
    answer = true;
    assert(answer == solve.isArmstrong(n));

    n = 123;
    answer = false;
    assert(answer == solve.isArmstrong(n));

    return 0;
}
