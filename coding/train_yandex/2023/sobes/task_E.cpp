// https://contest.yandex.ru/contest/8458/problems/E/
// Created by ruslan515 on 25.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int solving(string s1, string s2) {
        int answer = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 != n2) {
            return answer;
        }
        map<char, int> m1, m2;
        for (int i = 0; i < n1; ++i) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if (m1.size() != m2.size()) {
            return answer;
        } else {
            if (equal(m1.begin(), m1.end(), m2.begin())) {
                answer = 1;
            }
        }

        return answer;
    }
};

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    Solution solve;
    cout << solve.solving(s1, s2) << "\n";

    return 0;
}