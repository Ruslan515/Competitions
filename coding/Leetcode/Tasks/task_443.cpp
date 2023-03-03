// https://leetcode.com/problems/string-compression/
// Created by ruslan515 on 02.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int compress(vector<char>& chars) {
        int n = chars.size();
        string s = "";
        int idx = 0;
        char current = ' ';
        int cnt = 0;
        char temp;
        while (idx < n) {
            temp = chars[idx];
            if (temp == current) {
                ++cnt;
            } else {
                if (current != ' ') {
                    s += current;
                    if (cnt != 1) {
                        string cnt_string = to_string(cnt);
                        s += cnt_string;
                    }
                }
                current = temp;
                cnt = 1;
            }
            ++idx;
        }
        s += current;
        if (cnt != 1) {
            string cnt_string = to_string(cnt);
            s += cnt_string;
        }

        int len = s.size();
        for (int i = 0; i < len; ++i) {
            chars[i] = s[i];
        }
        return s.size();

    }
};

void read_data(vector<char>& chars, int & ans) {
    int n;
    cin >> n >> ans;
    char t;
    while (n > 0) {
        cin >> t;
        chars.push_back(t);
        n--;
    }

    return;
}

int main() {
    int t;
    cin >> t;
    while (t > - 1) {
        vector<char> chars;
        int ans;
        read_data(chars, ans);
        Solution solve;
        int temp = solve.compress(chars);
        assert(temp == ans);
        cout << temp << "\n";

    }

    return 0;
}