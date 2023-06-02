// https://leetcode.com/problems/find-the-highest-altitude/
// Created by ruslan515 on 31.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        int answer = 0;
        int tempSum = 0;
        for (int g: gain){
            tempSum += g;
            answer = max(answer, tempSum);
        }
        return answer;
    }
};

int main() {
    vector<int> gain;
    int answer;
    Solution solve;

    gain = {-5, 1, 5, 0, -7};
    answer = 1;
    assert(answer == solve.largestAltitude(gain));

    gain = {-4, -3, -2, -1, 4, 3, 2};
    answer = 0;
    assert(answer == solve.largestAltitude(gain));
    return 0;
}
