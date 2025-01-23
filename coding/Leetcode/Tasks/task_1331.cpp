// https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02
// Created by omega515 on 02.10.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        unordered_set<int> uSet(arr.begin(), arr.end());
        priority_queue<int> pq;
        for (int item: uSet) {
            pq.push(-1 * item);
        }

        unordered_map<int, int> mp;
        int i = 1;
        int val;
        while (!pq.empty()) {
            val = -1 * pq.top();
            pq.pop();
            mp[val] = i;
            ++i;
        }
        int key;
        for (i = 0; i < arr.size(); ++i) {
            key = arr[i];
            val = mp[key];
            answer.push_back(val);
        }


        return answer;
    }
};

int main() {
    vector<int> arr;
    vector<int> answer;
    Solution solve;

    arr = {40, 10, 20, 30};
    answer = {4, 1, 2, 3};
    assert(answer == solve.arrayRankTransform(arr));

    arr = {100, 100, 100};
    answer = {1, 1, 1};
    assert(answer == solve.arrayRankTransform(arr));

    arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    answer = {5, 3, 4, 2, 8, 6, 7, 1, 3};
    assert(answer == solve.arrayRankTransform(arr));

    return 0;
}
