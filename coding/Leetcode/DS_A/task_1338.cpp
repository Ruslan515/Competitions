// https://leetcode.com/problems/reduce-array-size-to-the-half/description/
// Created by omega515 on 10.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int> &arr) {
        int answer = 0;
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            ++mp[arr[i]];
        }
        priority_queue<int> pq;
        unordered_map<int, int>::iterator it = mp.begin();
        for (; it != mp.end(); ++it) {
            pq.push(it->second);
        }
        int count = 0;
        int i = 0;
        while (count < n / 2) {
            count += pq.top();
            pq.pop();
            ++i;
        }
        answer = i;

        return answer;
    }
};

int main() {
    vector<int> arr;
    int answer;
    Solution solve;

    arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    answer = 2;
    assert(answer == solve.minSetSize(arr));

    arr = {7, 7, 7, 7, 7, 7};
    answer = 1;
    assert(answer == solve.minSetSize(arr));

    return 0;
}
