// https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
// Created by omega515 on 11.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        vector<int> answer;
        map<int, int> mp;
        for (int num: arr1) {
            ++mp[num];
        }
        for (int num: arr2) {
            int count = mp[num];
            for (int i = 0; i < count; ++i) {
                answer.push_back(num);
            }
            mp.erase(num);
        }
        for (const auto &[key, count]: mp) {
            for (int i = 0; i < count; ++i) {
                answer.push_back(key);
            }
        }

        return answer;
    }
};

int main() {
    vector<int> arr1, arr2;
    vector<int> answer;
    Solution solve;

    arr1 = {26, 21, 11, 20, 50, 34, 1, 18}, arr2 = {21, 11, 26, 20};
    answer = {21, 11, 26, 20, 1, 18, 34, 50};
    assert(answer == solve.relativeSortArray(arr1, arr2));

    arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    answer = {2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19};
    assert(answer == solve.relativeSortArray(arr1, arr2));

    arr1 = {28, 6, 22, 8, 44, 17}, arr2 = {22, 28, 8, 6};
    answer = {22, 28, 8, 6, 17, 44};
    assert(answer == solve.relativeSortArray(arr1, arr2));

    return 0;
}
