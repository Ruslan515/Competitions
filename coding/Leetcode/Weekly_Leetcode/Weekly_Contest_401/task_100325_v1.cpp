// https://leetcode.com/contest/weekly-contest-401/problems/find-the-child-who-has-the-ball-after-k-seconds/
// Created by omega515 on 09.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfChild(int n, int k) {
    int passes = k % (2 * n - 2);
    if (passes <= n - 1) {
      return passes;
    } else {
      return 2 * n - 2 - passes;
    }
  }
};

int main() {
  int n, k;
  int answer;
  Solution solve;

  n = 5, k = 8;
  answer = 0;
  assert(answer == solve.numberOfChild(n, k));

  n = 2, k = 4;
  answer = 0;
  assert(answer == solve.numberOfChild(n, k));

  n = 3, k = 6;
  answer = 2;
  assert(answer == solve.numberOfChild(n, k));

  n = 2, k = 2;
  answer = 0;
  assert(answer == solve.numberOfChild(n, k));

  n = 5, k = 6;
  answer = 2;
  assert(answer == solve.numberOfChild(n, k));

  n = 3, k = 5;
  answer = 1;
  assert(answer == solve.numberOfChild(n, k));

  n = 4, k = 2;
  answer = 2;
  assert(answer == solve.numberOfChild(n, k));

  return 0;
}
