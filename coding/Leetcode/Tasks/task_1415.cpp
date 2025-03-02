// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19
// Created by omega515 on 19.02.2025.
//


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string getHappyString(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";


        int cnt = 3 * pow(2, (n - 1));

        if (cnt < k) {
            return answer;
        }

        vector<string> v;
        unordered_map<char, vector<char>> mp{
                {'a', {'b', 'c'}},
                {'c', {'a', 'b'}},
                {'b', {'a', 'c'}}
        };


        queue<string> queue1;
        queue1.push("a");
        queue1.push("b");
        queue1.push("c");
        string current;
        char lastChar;
        while (!queue1.empty()) {
            int sizeQ = queue1.size();
            for (int i = 0; i < sizeQ; ++i) {
                current = queue1.front();
                queue1.pop();
                if (current.size() == n) {
                    if (v.size() == (k - 1)) {
                        return current;
                    }
                    v.push_back(current);
                } else {
                    lastChar = current[current.size() - 1];
                    vector<char> nextChars = mp[lastChar];
                    for (char ch: nextChars) {
                        queue1.push(current + ch);
                    }
                }
            }
        }
        answer = v[k - 1];

        return answer;
    }
};

int main() {
    int n, k;
    string answer;
    Solution solve;

    n = 10, k = 100;
    answer = "abacbabacb";
    assert(answer == solve.getHappyString(n, k));

    n = 1, k = 4;
    answer = "";
    assert(answer == solve.getHappyString(n, k));

    n = 3, k = 9;
    answer = "cab";
    assert(answer == solve.getHappyString(n, k));

    n = 1, k = 3;
    answer = "c";
    assert(answer == solve.getHappyString(n, k));

    return 0;
}
