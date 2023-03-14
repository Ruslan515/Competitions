// https://leetcode.com/problems/shortest-way-to-form-string/
// Created by ruslan515 on 13.03.22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = source.size();
        set<char> set_source;
        for (int i = 0; i < n; ++i) {
            set_source.insert(source[i]);
        }

        int m = target.size();
        while (j < m) {
            while (j < m && i < n) {
                char temp = target[j];
                if (set_source.count(temp) == 0) {
                    return -1;
                }
                if (source[i] == target[j]) {
                    ++j;
                }
                ++i;
            }
            ++count;
            i = 0;
        }


        return count;
    }
};

void read_data(string& source, string& target) {
    cin >> source >> target;
    return;
}

int main() {
//    string source;
//    string target;
//    read_data(source, target);
    Solution s;
    assert(s.shortestWay("abc", "abcbc") == 2);
    assert(s.shortestWay("abc", "acdbc") == -1);
    assert(s.shortestWay("xyz", "xzyxz") == 3);
    assert(s.shortestWay("aaaaa", "aaaaaaaaaaaaa") == 3);

    return 0;
}