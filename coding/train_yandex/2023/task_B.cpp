// https://contest.yandex.ru/contest/8458/problems/B/
// Created by ruslan515 on 25.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solving(vector<int> &v) {
        int answer = 0;
        int left = 0, right = 0;
        int n = v.size();

        while (right < n) {
            while (right < n && v[right] == 1) {
                ++right;
            }
            int temp_size = right - left;
            answer = max(answer, temp_size);
            left = right;
            while (left < n && v[left] == 0) {
                ++left;
            }
            right = left;
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int temp;
    while (cin >> temp) {
        v.push_back(temp);
    }

    Solution solve;

    cout << solve.solving(v);

    return 0;
}