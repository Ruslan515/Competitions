// https://leetcode.com/problems/pascals-triangle/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 19.01.23.
//

#include <iostream>
#include <vector>

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
};

void read_data(int& numRows) {
    cin >> numRows;
    return;
}

int main() {
    int numRows;
    read_data(numRows);
    Solution solve;
    vector<vector<int>> ans = solve.generate(numRows);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}