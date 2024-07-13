// https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10
// Created by omega515 on 10.07.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<string> &logs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        vector<string> v;
        v.push_back("main");
        int n;
        for (string log: logs) {
            n = v.size();
            if (log == "../") {
                if (n > 1) {
                    v.pop_back();
                }
            } else if (log == "./") {
                continue;
            } else {
                v.push_back(log);
            }
        }
        answer = v.size() - 1;

        return answer;
    }
};

int main() {
    vector<string> logs;
    int answer;
    Solution solve;

    logs = {"d1/", "d2/", "../", "d21/", "./"};
    answer = 2;
    assert(answer == solve.minOperations(logs));

    logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    answer = 3;
    assert(answer == solve.minOperations(logs));

    logs = {"d1/", "../", "../", "../"};
    answer = 0;
    assert(answer == solve.minOperations(logs));

    return 0;
}
