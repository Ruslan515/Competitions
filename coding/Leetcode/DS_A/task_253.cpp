// https://leetcode.com/problems/meeting-rooms-ii/description/
// Created by ruslan515 on 30.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {

    }
};

int main() {
    vector<vector<int>> intervals;
    int answer;
    Solution solve;

    intervals = {{0,  30},
                 {5,  10},
                 {15, 20}};
    answer = 2;
    assert(answer == solve.minMeetingRooms(intervals));

    intervals = {{7, 10},
                 {2, 4}};
    answer = 1;
    assert(answer == solve.minMeetingRooms(intervals));

    intervals = {{13, 15},
                 {1,  13}};
    answer = 1;
    assert(answer == solve.minMeetingRooms(intervals));

    return 0;
}
