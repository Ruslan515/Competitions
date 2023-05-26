//
// Created by ruslan515 on 26.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        string s;
        string FizzBuzz = "FizzBuzz";
        string Fizz = "Fizz";
        string Buzz = "Buzz";

        for (int i = 1; i < n + 1; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                s = FizzBuzz;
            } else if (i % 3 == 0) {
                s = Fizz;
            } else if (i % 5 == 0) {
                s = Buzz;
            } else {
                s = to_string(i);
            }
            answer.push_back(s);
        }

        return answer;
    }
};

int main() {
    int n;
    vector<string> answer;
    Solution solve;

    n = 15;
    answer = {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};
    assert(solve.fizzBuzz(n) == answer);

    n = 3;
    answer = {"1", "2", "Fizz"};
    assert(solve.fizzBuzz(n) == answer);

    n = 5;
    answer = {"1", "2", "Fizz", "4", "Buzz"};
    assert(solve.fizzBuzz(n) == answer);

    return 0;
}