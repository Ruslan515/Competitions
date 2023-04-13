// https://leetcode.com/problems/k-th-symbol-in-grammar/description/
// Created by ruslan515 on 10.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<string> v;
        v.push_back("0");
        map<char, string> mp = {{'0', "01"},
                                {'1', "10"}};
        for (int i = 1; i < n; ++i) {
            string temp = "";
            string prev = v[i - 1];
            int l = prev.size();
            for (int j = 0; j < l; ++j) {
                char t = prev[j];
                string x = mp[t];
                temp += x;
            }
            v.push_back(temp);
        }

        int answer = v[n - 1][k - 1] - '0';
        return answer;
    }
};

int main() {
    int n, k;
    Solution solve;

    n = 1;
    k = 1;
    assert(solve.kthGrammar(n, k) == 0);

    n = 2;
    k = 1;
    assert(solve.kthGrammar(n, k) == 0);

    n = 2;
    k = 2;
    assert(solve.kthGrammar(n, k) == 1);

    return 0;
}
