//
// Created by ruslan515 on 16.01.23.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool confusingNumber(int n) {
        bool ans = false;
        string num = to_string(n);
        string s = "";
        for (int i = 0; i < num.size(); ++i) {
            int d = num[i] - '0';
            if (d == 2 || d == 3 || d == 4 || d == 5 || d == 7) {
                ans = false;
                return ans;
            }
            char rotate_d;
            switch (d) {
                case 0:
                    rotate_d = '0';
                    break;
                case 1:
                    rotate_d = '1';
                    break;
                case 6:
                    rotate_d = '9';
                    break;
                case 8:
                    rotate_d = '8';
                    break;
                case 9:
                    rotate_d = '6';
                    break;
            }
            s = rotate_d + s;
        }
        int rotate_num = stoi(s);
        if (rotate_num != n) ans = true;

        return ans;
    }
};


void read_data(int& n) {
    cin >> n;
    return;
}

int main() {
    int n;
    read_data(n);
    Solution solve;
    cout << solve.confusingNumber(n);
    return 0;
}