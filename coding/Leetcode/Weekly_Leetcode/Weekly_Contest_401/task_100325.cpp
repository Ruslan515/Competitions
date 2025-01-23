// https://leetcode.com/contest/weekly-contest-401/problems/find-the-child-who-has-the-ball-after-k-seconds/
// Created by omega515 on 09.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfChild(int n, int k) {
    int answer = 0;
    if (n > k) {
      answer = k;
    } else {
      if (k % n == 0) {
        int d = k / n;
        if (d % 2 != 0) {
          answer = 0;
        } else {
          answer = n - 1;
        }

        return answer;
      }
      int kk = k + 1;
      int d = kk / n;
      int m = kk % n;
      if (d % 2 == 0 && m == 0) {
        answer = 1;
      } else if (d % 2 != 0) {
        answer = n - m - 1;
      } else if (d % 2 == 0 && m == 1) {
        answer = n - 1;
      } else {
        answer = kk + 1;
      }
    }

    return answer;
  }
};

int main() {
  int n, k;
  int answer;
  Solution solve;

  n = 2, k = 4;
  answer = 0;
  assert(answer == solve.numberOfChild(n, k));

  n = 3, k = 6;
  answer = 2;
  assert(answer == solve.numberOfChild(n, k));

  n = 2, k = 2;
  answer = 0;
  assert(answer == solve.numberOfChild(n, k));

  n = 5, k = 8;
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
