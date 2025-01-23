// https://leetcode.com/contest/weekly-contest-335/problems/split-the-array-to-make-coprime-products/
// Created by ruslan515 on 05.03.23.
//

/*
557663 280817 472963 156253 273349 884803 756869 763183 557663 964357 821411 887849 891133 453379 464279 574373 852749 15031 156253 360169 526159 410203 6101 954851 860599 802573 971693 279173 134243 187367 896953 665011 277747 439441 225683 555143 496303 290317 652033 713311 230107 770047 308323 319607 772907 627217 119311 922463 119311 641131 922463 404773 728417 948281 612373 857707 990589 12739 9127 857963 53113 956003 363397 768613 47981 466027 981569 41597 87149 55021 600883 111953 119083 471871 125641 922463 562577 269069 806999 981073 857707 831587 149351 996461 432457 10903 921091 119083 72671 843289 567323 317003 802129 612373
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gcd (long long a, long long b) {
        while (b) {
            a %= b;
            swap (a, b);
        }
        return a;
    }

    int findValidSplit(vector<int>& nums) {
        int n = nums.size();

        int answer = -1;
        for (int idx = 0; idx <= n - 2; ++idx) {
            bool label = false;
            for(int i = 0; i <= idx; ++i) {
                int num1 = nums[i];
                for (int j = idx + 1; j < n; ++j) {
                    int num2 = nums[j];
                    if (gcd(num1, num2) != 1) {
                        label = true;
                        break;
                    }
                }
                if (label) {
                    break;
                }
            }
            if(!label) {
                answer = idx;
                break;
            }
        }

        return answer;
    }
};

void read_data(vector<int>& nums) {
    int t;
    while (cin >> t)
        nums.push_back(t);
    return;
}

int main() {
    vector<int> nums;
    read_data(nums);
    Solution solve;

    cout << solve.findValidSplit(nums);

    return 0;
}