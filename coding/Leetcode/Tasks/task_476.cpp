// https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
// Created by omega515 on 22.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        int d = 2;
        unsigned int st = 1;
        int mask = 1;
        unsigned int tmp;
        while (num != 0) {
            tmp = (unsigned int)num & mask;
            if (tmp == 0) {
                answer += st;
            }

            num >>= 1;
            st *= d;
        }

        return answer;
    }
};


int main() {
    int num;
    int answer;
    Solution solve;

    num = 2147483647;
    answer = 2;
    assert(answer == solve.findComplement(num));

    num = 5;
    answer = 2;
    assert(answer == solve.findComplement(num));


    num = 1;
    answer = 0;
    assert(answer == solve.findComplement(num));

    return 0;
}
