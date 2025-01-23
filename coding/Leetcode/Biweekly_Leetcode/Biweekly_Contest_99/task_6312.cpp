// https://leetcode.com/contest/biweekly-contest-99/problems/split-with-minimum-sum/
// Created by ruslan515 on 04.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNum(vector<int> &numX) {
        int t = 0;
        int n = numX.size();
        int numG;
        for (int i = 0; i < n; ++i) {
            numG = numX[i];
            t += numG * pow(10, n - i - 1);
        }
        return t;
    }

    int splitNum(int num) {
        vector<int> nums;
        while (num != 0) {
            int d = num % 10;
            nums.push_back(d);
            num /= 10;
        }

        vector<int> num1, num2;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        int t1, t2;
        for (int i = 0; i < n - 1; i += 2) {
            t1 = nums[i];
            num1.push_back(t1);
            t2 = nums[i + 1];
            num2.push_back(t2);
        }
        if (n % 2 != 0) {
            num1.push_back(nums[n - 1]);
        }

        t1 = getNum(num1);
        t2 = getNum(num2);
//        t1 = 0;
//        int n1 = num1.size();
//        int t;
//        for (int i = 0; i < n1; ++i) {
//            t = num1[i];
//            t1 += t * pow(10, n1 - i);
//        }


        int ans = t1 + t2;
        return ans;
    }
};

void read_data(int &num) {
    cin >> num;
    return;
}

int main() {
    int num;
    read_data(num);
    Solution solve;
    assert(solve.splitNum(4325) == 59);

    assert(solve.splitNum(687) == 75);

    return 0;
}