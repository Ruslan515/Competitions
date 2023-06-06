// https://leetcode.com/problems/toss-strange-coins/
// Created by ruslan515 on 05.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double probabilityOfHeads(vector<double> &prob, int target) {
        double answer = 0;
        int n = prob.size();
        if (prob[0] == 0) {
            int i = 1;
            while (prob[i] == prob[i - 1]){
                ++i;
            }
            if (i == n) {
                answer = 1;
                return answer;
            }
        }

        if (prob[0] == 1) {
            int i = 1;
            while (prob[i] == prob[i - 1]){
                ++i;
            }
            if (i == n) {
                answer = 0;
                return answer;
            }
        }

        if (target == 0) {
            answer = 1;
            for (int k = 0; k < n; ++k) {
                answer *= (1 - prob[k]);
            }
            return answer;
        }

        int mask = 1;
        int ix = 1;

        while (ix < 1 << n) {
            // count ones
            vector<bool> v(n, false);
            double p = 1;
            int count = 0;
            int i = ix;
            int t = 0;
            while (i != 0) {
                int d = i & mask;
                if (d) {
                    ++count;
                    v[t] = true;
                }
                i >>= 1;
                ++t;
            }
            if (count == target) {
                for (int j = 0; j < n; ++j) {
                    if (v[j]) {
                        p *= prob[j];
                    } else {
                        p *= (1 - prob[j]);
                    }
                }
                answer += p;
            }
            ++ix;
        }

        return answer;
    }
};

int main() {
    vector<double> prob;
    int target;
    double answer;
    Solution solve;

    prob = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    target = 99;
    answer = 0;
    assert(solve.probabilityOfHeads(prob, target) == answer);

    prob = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, target = 9;
    answer = 0;
    assert(solve.probabilityOfHeads(prob, target) == answer);

    prob = {0.4}, target = 1;
    answer = 0.40000;
    assert(solve.probabilityOfHeads(prob, target) == answer);

    prob = {0.5, 0.5, 0.5, 0.5, 0.5}, target = 0;
    answer = 0.03125;
    assert(solve.probabilityOfHeads(prob, target) == answer);


    return 0;
}