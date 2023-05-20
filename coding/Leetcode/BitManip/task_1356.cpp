// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Created by ruslan515 on 20.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<int> answer;
        map<int, vector<int>> mp;

        for (auto num: arr) {
            int mask = 1;
            int count = 0;
            int z = num;
            while (num != 0) {
                int x = num & mask;
                if (x) {
                    ++count;
                }
                num >>= 1;
            }
            mp[count].push_back(z);
        }

        map<int, vector<int>>::iterator it = mp.begin();
        for (; it != mp.end(); ++it) {
            vector<int> temp = it->second;
            sort(temp.begin(), temp.end());
            answer.insert(answer.end(), temp.begin(), temp.end());
        }

        return answer;
    }
};

int main() {
    vector<int> arr, answer;
    Solution solve;

    arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    answer = {0, 1, 2, 4, 8, 3, 5, 6, 7};
    assert(solve.sortByBits(arr) == answer);

    arr = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    answer = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    assert(solve.sortByBits(arr) == answer);

    return 0;
}