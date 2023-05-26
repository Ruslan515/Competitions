// https://leetcode.com/problems/utf-8-validation/
// Created by ruslan515 on 26.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkNextNByte(int start, vector<int> &data, int countBit) {
        bool answer = true;
        int n = data.size();
        if (countBit + start - 1 > n) {
            answer = false;
            return answer;
        }
        int mask, d;

        for (int j = 0; j < countBit - 1 && (start + j) < n; ++j) {
            int temp = data[start + j];
            temp >>= 6;
            mask = 1 << 1;
            d = mask ^ temp;
            if (d != 0) {
                answer = false;
                return answer;
            }
        }
        return answer;
    }

    bool validUtf8(vector<int> &data) {
        bool answer = true;
        int n = data.size();
        int i = 0;

        int current, mask, d;
        while (i < n) {
            current = data[i];
            mask = 1 << 7;
            d = current & mask; // 0000000011101011
            if (d == 0) {
                ++i;
            } else if (((current >> 3) ^ 0b11110) == 0) { // 4 byte
                bool test = checkNextNByte(i + 1, data, 4);
                if (!test) {
                    answer = false;
                    break;
                }
                i += 4;
            } else if (((current >> 4) ^ 0b1110) == 0) { // 3 byte
                bool test = checkNextNByte(i + 1, data, 3);
                if (!test) {
                    answer = false;
                    break;
                }
                i += 3;
            } else if (((current >> 5) ^ 0b110) == 0) { // 2 byte
                bool test = checkNextNByte(i + 1, data, 2);
                if (!test) {
                    answer = false;
                    break;
                }
                i += 2;
            } else { // error
                answer = false;
                break;
            }
        }
        return answer;
    }
};

int main() {
    vector<int> data;
    bool answer;
    Solution solve;

    data = {230, 136, 145};
    answer = true;
    assert(solve.validUtf8(data) == answer);

    data = {235, 140, 4};
    answer = false;
    assert(solve.validUtf8(data) == answer);

    data = {197, 130, 1};
    answer = true;
    assert(solve.validUtf8(data) == answer);

    return 0;
}