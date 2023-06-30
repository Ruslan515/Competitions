// https://leetcode.com/problems/meeting-rooms/
// Created by ruslan515 on 30.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        bool answer = true;
        if (intervals.size() == 0) {
            return answer;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> current, next;
        for (int i= 0; i < intervals.size() - 1; ++i) {
            current = intervals[i];
            next = intervals[i + 1];
            int end_current = current[1];
            int start_next = next[0];
            if (start_next < end_current) {
                answer = false;
                break;
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> intervals;
    bool answer;
    Solution solve;

    intervals = {{13,  15},
                 {1,  13}};
    answer = true;
    assert(answer == solve.canAttendMeetings(intervals));

    intervals = {{0,  30},
                 {5,  10},
                 {15, 20}};
    answer = false;
    assert(answer == solve.canAttendMeetings(intervals));

    intervals = {{7, 10},
                 {2, 4}};
    answer = true;
    assert(answer == solve.canAttendMeetings(intervals));

    return 0;
}
