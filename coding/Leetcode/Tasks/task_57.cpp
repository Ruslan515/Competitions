// https://leetcode.com/problems/insert-interval/description/
// Created by ruslan515 on 17.01.23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Returns true if the intervals a and b have a common element.
    bool doesIntervalsOverlap(vector<int>& a, vector<int>& b) {
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }

    // Return the interval having all the elements of intervals a and b.
    vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    // Insert the interval newInterval, into the list interval keeping the sorting order intact.
    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isIntervalInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                // Found the position, insert the interval and break from the loop.
                intervals.insert(intervals.begin() + i, newInterval);
                isIntervalInserted = true;
                break;
            }
        }

        // If there is no interval with a greater value of start value,
        // then the interval must be inserted at the end of the list.
        if (!isIntervalInserted) {
            intervals.push_back(newInterval);
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Insert the interval first before merge processing.
        insertInterval(intervals, newInterval);

        vector<vector<int>> answer;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> currInterval = {intervals[i][0], intervals[i][1]};
            // Merge until the list gets exhausted or no overlap is found.
            while (i < intervals.size() && doesIntervalsOverlap(currInterval, intervals[i])) {
                currInterval = mergeIntervals(currInterval, intervals[i]);
                i++;
            }
            // Decrement to ensure we don't skip the interval due to outer for-loop incrementing.
            i--;
            answer.push_back(currInterval);
        }

        return answer;
    }
};

//class Solution {
//public:
//    void insert_remaining(vector<vector<int>>& intervals, vector<vector<int>>& ans, int idx) {
//        int n = intervals.size();
//        for (int i = idx; i < n; ++i) {
//            ans.push_back(intervals[i]);
//        }
//        return;
//    }
//
//    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//        vector<vector<int>> ans;
//        int n = intervals.size();
//        if (n == 0) {
//            ans.push_back(newInterval);
//        }
//        int start = newInterval[0];
//        int end = newInterval[1];
//        vector<int> to_push;
//
//        int i;
//        for (i = 0; i < n; ++i) {
//            int start_i = intervals[i][0];
//            int end_i = intervals[i][1];
//
//            int start_next = intervals[i + 1][0];
//
//            if (start >= start_i && start <= end_i) {
//                to_push.push_back(start_i);
//                if (end <= end_i) {
//                    to_push.push_back(end_i);
//                    ans.push_back(to_push);
//                    insert_remaining(intervals, ans, i + 1);
//                    return ans;
//                } else if (end < start_next) {
//                    to_push.push_back(end);
//                    ans.push_back(to_push);
//                    insert_remaining(intervals, ans, i + 1);
//                    return ans;
//                } else {
//                    break;
//                }
//            } else {
//                ans.push_back(intervals[i]);
//            }
//        }
//
//        int j;
//        for (j = i + 1; j < n; ++j) {
//            int start_i = intervals[j][0];
//            int end_i = intervals[j][1];
//
//            if (end >= start_i && end <= end_i) {
//                to_push.push_back(end_i);
//                ans.push_back(to_push);
//                insert_remaining(intervals, ans, j + 1);
//                return ans;
//            }
//        }
//
//        return ans;
//    }
//};

void read_data(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        cin >> a >> b;
        t.push_back(a);
        t.push_back(b);
        intervals.push_back(t);
    }
    cin >> a >> b;
    newInterval.push_back(a);
    newInterval.push_back(b);
    return;
}

int main() {
    vector<vector<int>> intervals;
    vector<int> newInterval;
    read_data(intervals, newInterval);
    Solution solve;
    vector<vector<int>> ans = solve.insert(intervals, newInterval);
    for (int i = 0; i < ans.size(); ++i) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "], ";
    }
    cout << "\n";

    return 0;
}