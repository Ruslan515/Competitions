// https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23
// Created by omega515 on 23.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        string answer = "";
        vector<pair<int, int>> v;
        int numerator, denominator;
        string numeratorStr, denominatorStr;
        int sign = 1;
        int i = 0;
        if (expression[0] == '-') {
            sign = -1;
            i = 1;
        }
        int n = expression.size();
        while (i < n) {
            numeratorStr = "";
            while (isdigit(expression[i])) {
                numeratorStr += expression[i];
                ++i;
            }
            numerator = sign * stoi(numeratorStr);
            ++i;
            denominatorStr = "";
            while (isdigit(expression[i])) {
                denominatorStr += expression[i];
                ++i;
            }
            denominator = stoi(denominatorStr);
            sign = expression[i] == '-' ? -1 : 1;
            v.push_back({numerator, denominator});
            ++i;
        }

        if (v.size() == 1) {
            numeratorStr = "";
            numerator = v[0].first;
            numeratorStr += to_string(numerator);
            denominatorStr = to_string(v[0].second);
            answer = numeratorStr + "/" + denominatorStr;
            return answer;
        }

        int lcmCurr = v[0].second;
        for (i = 1; i < v.size(); ++i) {
            lcmCurr = lcm(lcmCurr, v[i].second);
        }

        int x = 0;
        for (i = 0; i < v.size(); ++i) {
            x += lcmCurr / v[i].second * v[i].first;
        }
        if (x % lcmCurr == 0) {
            numerator = x / lcmCurr;
            numeratorStr = to_string(numerator);
            denominatorStr = "1";
        } else {
            int gcdC = gcd(x, lcmCurr);

            numerator = x / gcdC;
            numeratorStr = to_string(numerator);

            denominator = lcmCurr / gcdC;
            denominatorStr = to_string(denominator);
        }
        answer = numeratorStr + "/" + denominatorStr;

        return answer;
    }
};


int main() {
    string expression;
    string answer;
    Solution solve;

    expression = "-1/2+1/2+1/3";
    answer = "1/3";
    assert(answer == solve.fractionAddition(expression));

    expression = "1/3-1/2";
    answer = "-1/6";
    assert(answer == solve.fractionAddition(expression));

    expression = "-1/2";
    answer = "-1/2";
    assert(answer == solve.fractionAddition(expression));

    expression = "-1/2+1/2";
    answer = "0/1";
    assert(answer == solve.fractionAddition(expression));

    return 0;
}
