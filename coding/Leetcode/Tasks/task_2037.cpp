// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13
// Created by omega515 on 13.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students) {
        int answer = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size();
        int diff;
        for (int i = 0; i < n; ++i) {
            diff = abs(students[i] - seats[i]);
            answer += diff;
        }

        return answer;
    }
};

int main() {
    vector<int> seats, students;
    int answer;
    Solution solve;

    seats = {3, 1, 5}, students = {2, 7, 4};
    answer = 4;
    assert(answer == solve.minMovesToSeat(seats, students));

    seats = {4, 1, 5, 9}, students = {1, 3, 2, 6};
    answer = 7;
    assert(answer == solve.minMovesToSeat(seats, students));

    seats = {3, 1, 5}, students = {2, 7, 4};
    answer = 4;
    assert(answer == solve.minMovesToSeat(seats, students));

    return 0;
}
