// https://leetcode.com/problems/valid-parentheses/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 23.12.22.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        while (s.size() != 0) {
            int i = 0;
            int n = s.size();
            for (; i < n - 1; ++i) {
                bool t1 = (s[i] == '(' && s[i + 1] == ')');
                bool t2 = (s[i] == '{' && s[i + 1] == '}');
                bool t3 = (s[i] == '[' && s[i + 1] == ']');
                if  (t1 || t2 || t3) {
                    s.erase(i, 2);
                    break;
                }
            }
            int t = s.size();
            if (i == n - 1) {
                break;
            }
        }

        if (s.size() != 0) {
            ans = false;
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