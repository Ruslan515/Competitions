//
// Created by ruslan515 on 23.12.22.
//

#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        int n = s.size();
        map<char, char> mp = {
                {')', '('},
                {'}', '{'},
                {']', '['}
        };

        stack<char> st;
        for (int i = 0; i < n; ++i) {
            char temp = s[i];
            if (mp.find(temp) == mp.end()) {
                // open
                st.push(temp);
            } else {
                // close
                if (st.empty()) {
                    ans = false;
                    break;
                }
                char top = st.top();
                if (mp[temp] == top) {
                    st.pop();
                } else {
                    ans = false;
                    break;
                }
            }
        }
        if (!st.empty()) {
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