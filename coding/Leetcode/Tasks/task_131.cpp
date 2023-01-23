// https://leetcode.com/problems/palindrome-partitioning/
// Created by ruslan515 on 21.01.23.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    void split_str(string s, vector<vector<string>>& ans) {
        int n = s.size();
        if (n < 1)
            return;
        else {
            vector<string> temp;
            for (int i = 0; i < n; ++i) {
                string sub_str = s.substr(0, i + 1);
                temp.push_back(sub_str);
            }
            ans.push_back(temp);
        }

        split_str(s.substr(1, n), ans);
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        split_str(s, ans);

        return ans;
    }
};

void read_data(string& s) {
    cin >> s;
}

int main() {
    string s;
    read_data(s);
    Solution solve;
    vector<vector<string>> ans = solve.partition(s);
    for (vector<string> v: ans) {
        for (string s: v) {
            cout << s << "\t";
        }
        cout << "\n";
    }
    return 0;
}