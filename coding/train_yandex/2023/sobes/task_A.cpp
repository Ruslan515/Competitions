// https://contest.yandex.ru/contest/8458/problems/?nc=UopFQbsT
// Created by ruslan515 on 25.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solving(string &j, string &s) {
        int answer = 0;
        if (j.size() == 0) {
            return answer;
        }
        set<char> d(j.begin(), j.end());
        for (char ch: s){
            if (d.count(ch) != 0) {
                ++answer;
            }
        }

        return answer;
    }
};
int main() {
    string j, s;
    int answer;
    Solution solve;

    answer = 4;
    cin >> j; //j = "ab";
    cin >> s; //s = "aabbccd";
//    assert(answer == solve.solving(j, s));
    cout << solve.solving(j, s);

}