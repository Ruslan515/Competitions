// https://leetcode.com/problems/unique-number-of-occurrences/description/
// Created by ruslan515 on 18.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        bool answer = true;
        map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            if (!mp.count(arr[i])) {
                mp.insert(make_pair(arr[i], 0));
            } else {
                ++mp[arr[i]];
            }
        }
        map<int, int>::iterator it = mp.begin();
        set<int> set_count;
        for (; it != mp.end(); ++it) {
            if (set_count.count(it->second)) {
                answer = false;
                break;
            } else {
                set_count.insert(it->second);
            }
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
    assert(solve.uniqueOccurrences(arr) == answer);

    arr = {1, 2};
    answer = false;
    assert(solve.uniqueOccurrences(arr) == answer);

    arr = arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    answer = true;
    assert(solve.uniqueOccurrences(arr) == answer);

    return 0;
}