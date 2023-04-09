// https://leetcode.com/problems/pascals-triangle-ii/description/
// Created by ruslan515 on 09.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> t(i, 1);
            for (int j = 2; j < i; ++j) {
                int x = ans[i - 1 - 1][j - 1 - 1];
                int y = ans[i - 1 - 1][j - 1];
                int sums = x + y;
                t[j - 1] = sums;
            }
            ans.push_back(t);
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> tr = generate(rowIndex + 1);
        vector<int> answer = tr[rowIndex];
        return answer;
    }
};

//class Solution {
//public:
//
//    int getPascal(int rowIndex, int i) {
//        if (rowIndex == 1 || rowIndex == i || i <= 0) {
//            return 1;
//        }
//        int temp = getPascal(rowIndex - 1, i - 1) + getPascal(rowIndex - 1, i);
//        return temp;
//
//    }
//
//    vector<int> getRow(int rowIndex) {
//        int n = rowIndex + 1;
//        vector<int> answer(n, 1);
//        for (int i = 1; i < n - 1; ++i) {
//            int temp = getPascal(rowIndex, i);
//            answer[i] = temp;
//        }
//        return answer;
//    }
//};

int main() {
    Solution solve;
    int rowIndex;
    vector<int> ans;

    ans = {1, 2, 1};
    rowIndex = 2;
    assert(solve.getRow(rowIndex) == ans);

    ans = {1, 3, 3, 1};
    rowIndex = 3;
    assert(solve.getRow(rowIndex) == ans);

    ans = {1};
    rowIndex = 0;
    assert(solve.getRow(rowIndex) == ans);

    ans = {1, 1};
    rowIndex = 1;
    assert(solve.getRow(rowIndex) == ans);

    return 0;
}