// https://leetcode.com/problems/can-place-flowers/
// Created by ruslan515 on 20.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if (n == 0) {
            return true;
        } else if(n == 1 && size == 1 && flowerbed[0] == 0) {
            return true;
        }
        bool answer = false;
        int cntZero = 0;
        int i = 0;
        bool startZero = true;
        while (i < size) {
            while (i < size && flowerbed[i] == 1) {
                ++i;
                startZero = false;
            }
            if (i == size) {
                break;
            }
            int cntTemp = 0;
            while (i < size && flowerbed[i] == 0) {
                ++i;
                ++cntTemp;
            }
            if (cntTemp > 2) {
                int cntLocalZero;
                int t = 1;
                if (startZero && i == size) {
                    t = 0;
                }
                if (!startZero && i < size) {
                    t = 2;
                }
                cntTemp -= t;
                cntLocalZero = cntTemp / 2;
                cntLocalZero += cntTemp % 2;
                cntZero += cntLocalZero;
            } else if (cntTemp == 2) {
                if (i == 2 || i == size) {
                    cntZero += 1;
                }
            }
        }
        if (cntZero >= n) {
            answer = true;
        }
        return answer;
    }
};

void read_data(vector<int>& flowerbed, int &n) {
    cin >> n;
    int t;
    while (cin >> t)
        flowerbed.push_back(t);
    return;
}

int main() {
    vector<int> flowerbed;
    int n;
    read_data(flowerbed, n);
    Solution solve;
    cout << solve.canPlaceFlowers(flowerbed, n);

    return 0;
}