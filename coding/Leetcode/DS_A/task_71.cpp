// https://leetcode.com/problems/simplify-path/description/
// Created by Ruslan Khalikov on 20.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string answer = "";
        answer += path[0];
        char temp;
        for (int i = 1; i < n; ++i) {
            temp = path[i];
            if (temp == '/') {
                if (answer[answer.size() - 1] != '/') {
                    answer += temp;
                }
            } else if (temp == '.') {

            }
        }

        return answer;
    }
};

int main() {
    string path, answer;
    Solution solve;

    path = "/home/";
    answer = "/home";
    assert(answer == solve.simplifyPath(path));

    path = "/../";
    answer = "/";
    assert(answer == solve.simplifyPath(path));

    path = "/home//foo/";
    answer = "/home/foo";
    assert(answer == solve.simplifyPath(path));

    return 0;
}