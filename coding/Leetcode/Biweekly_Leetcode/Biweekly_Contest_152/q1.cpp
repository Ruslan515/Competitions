// https://leetcode.com/contest/biweekly-contest-152/problems/unique-3-digit-even-numbers/description/
// Created by omega515 on 15.03.25.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int> &digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        unordered_map<int, int> freq;
        for (int num: digits) {
            ++freq[num];
        }
        int maxDigit = *max_element(digits.begin(), digits.end());
        int first, second, third, val1, val2, val3;
        for (int num = 100; num <= maxDigit * 100 + maxDigit * 10 + maxDigit; num += 2) {
            first = num / 100;
            second = (num % 100) / 10;
            third = num % 10;
            if (freq.find(first) != freq.end() && freq.find(second) != freq.end() && freq.find(third) != freq.end()) {
                --freq[first];
                --freq[second];
                --freq[third];
                if (freq[first] >= 0 && freq[second] >= 0 && freq[third] >= 0) {
                    ++answer;
                }
                ++freq[first];
                ++freq[second];
                ++freq[third];
            }
        }

        return answer;
    }
};

int main() {
    vector<int> digits;
    int answer;
    Solution solve;

    digits = {1, 2, 3, 4};
    answer = 12;
    assert(answer == solve.totalNumbers(digits));

    digits = {0, 2, 2};
    answer = 2;
    assert(answer == solve.totalNumbers(digits));

    digits = {6, 6, 6};
    answer = 1;
    assert(answer == solve.totalNumbers(digits));

    digits = {1, 3, 5};
    answer = 0;
    assert(answer == solve.totalNumbers(digits));

    return 0;
}
