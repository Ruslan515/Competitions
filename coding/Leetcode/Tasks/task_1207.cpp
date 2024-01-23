// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17
// Created by omega515 on 17.01.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        bool answer = true;
        unordered_map<int, int> mp;
        for (int num: arr) {
            ++mp[num];
        }
        unordered_map<int, int> :: iterator it = mp.begin();
        set<int> set1;
        int val;
        for (; it != mp.end(); ++it) {
            val = it->second;
            if (set1.find(val) != set1.end()) {
                answer = false;
                break;
            }
            set1.insert(val);
        }

        return answer;
    }
};

int main() {
    vector<int> arr;
    bool answer;
    Solution solve;

    arr = {1, 2, 2, 1, 1, 3};
    answer = true;
    assert(answer == solve.uniqueOccurrences(arr));

    arr = {1, 2};
    answer = false;
    assert(answer == solve.uniqueOccurrences(arr));

    arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    answer = true;
    assert(answer == solve.uniqueOccurrences(arr));

    return 0;
}