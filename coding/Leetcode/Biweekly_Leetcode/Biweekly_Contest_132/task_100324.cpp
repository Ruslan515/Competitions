// https://leetcode.com/contest/biweekly-contest-132/problems/clear-digits/
// Created by omega515 on 08.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    static string clearDigits(string s)
    {
        string answer;
        stack<char> st1, st2;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i)
        {
            st1.push(s[i]);
        }
        char top;
        while (!st1.empty())
        {
            top = st1.top();
            st1.pop();
        }


        return answer;
    }
};

int main()
{
    string s;
    string answer;
    Solution solve;

    s = "abc";
    answer = "abc";
    assert(answer == solve.clearDigits(s));

    s = "cb34";
    answer = "";
    assert(answer == solve.clearDigits(s));

    return 0;
}
