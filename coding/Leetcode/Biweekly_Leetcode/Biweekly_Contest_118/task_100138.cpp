// https://leetcode.com/contest/biweekly-contest-118/problems/maximize-area-of-square-hole-in-grid/
// Created by omega515 on 25.11.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars) {
        int answer;
        set<int> s1, s2;

        for (int i = 1; i <= n + 2; ++i) {
            s1.insert(i);
        }
        for (int i = 1; i <= m + 2; ++i) {
            s2.insert(i);
        }
        for (int bar: hBars) {
            s1.erase(bar);
        }
        for (int bar: vBars) {
            s2.erase(bar);
        }

        vector<int> list1(s1.begin(), s1.end());
        vector<int> list2(s2.begin(), s2.end());

//        for (int it : s1) {
//            list1.push_back(it);
//        }
//        for (int it : s2) {
//            list2.push_back(it);
//        }

//        sort(list1.begin(), list1.end());
//        sort(list2.begin(), list2.end());

        int maxH = 0, p1 = 0, maxV = 0, p2 = 0;
        for (int i : list1){
            maxH = max(maxH, i - p1);
            p1 = i;
        }

        for (int i : list2){
            maxV = max(maxV, i - p1);
            p1 = i;
        }

        answer = min(maxH, maxV);
        answer = answer * answer;

        return answer;
    }
};

int main() {
    int n, m;
    vector<int> hBars, vBars;
    int answer;
    Solution solve;

    n = 2, m = 1, hBars = {2, 3}, vBars = {2};
    answer = 4;
    assert(answer == solve.maximizeSquareHoleArea(n, m, hBars, vBars));

    n = 1, m = 1, hBars = {2}, vBars = {2};
    answer = 4;
    assert(answer == solve.maximizeSquareHoleArea(n, m, hBars, vBars));

    n = 2, m = 3, hBars = {2, 3}, vBars = {2, 3, 4};
    answer = 9;
    assert(answer == solve.maximizeSquareHoleArea(n, m, hBars, vBars));

    return 0;
}

