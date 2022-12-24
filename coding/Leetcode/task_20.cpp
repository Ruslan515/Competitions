//
// Created by ruslan515 on 23.12.22.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        int count_round = 0;
        int count_curly = 0;
        int count_sq = 0;
        int n = s.size();
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i += 2) {
                bool t1 = !(s[i] == '(' && s[i + 1] == ')');
                bool t2 = (!(s[i] == '{' && s[i + 1] == '}'));
                bool t3 = (!(s[i] == '[' && s[i + 1] == ']'));

                if (t1 && t2 && t3) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};

void read_data(string& s) {
    cin >> s;
    return;
}

int main() {
    string s;
    read_data(s);
    Solution solve;
    std::cout << solve.isValid(s);
    return 0;
}