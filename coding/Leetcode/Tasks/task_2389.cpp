// https://leetcode.com/problems/longest-subsequence-with-limited-sum/
// Created by ruslan515 on 25.12.22.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> vec_sums(n, 0);
        int temp_sum = 0;
        for (int i = 0; i < n; i++) {
            temp_sum += nums[i];
            vec_sums[i] = temp_sum;
        }

        for (int q: queries ) {
            int i = 0;
            while (i < n && vec_sums[i] <= q) {
                ++i;
            }
            answer.push_back(i);
        }

        return answer;
    }
};

void read_data(vector<int>& nums, vector<int>& queries) {
    string s;
    getline(cin, s);
    istringstream iss_n(s);
    for (int x; iss_n >> x; )
        nums.push_back(x);

    getline(cin, s);
    istringstream iss_q(s);
    for (int x; iss_q >> x; )
        queries.push_back(x);

    return;
}

int main() {
    vector<int> nums;
    vector<int> queries;
    read_data(nums, queries);
    Solution solve;

    vector<int> answer = solve.answerQueries(nums, queries);
    for (int a: answer)
        cout << a << " ";
    cout << "\n";
    return 0;
}