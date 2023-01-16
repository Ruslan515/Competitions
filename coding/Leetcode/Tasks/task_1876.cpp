//
// Created by ruslan515 on 16.01.23.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        if (s.size() >= 3) {
            int k = 3;
            for (int i = 0; i < s.size() - k + 1; ++i) {
                if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
                    ++ans;
                }
            }
        }
        return ans;
    }

//    int countGoodSubstrings(string s) {
//        int ans = 0;
//        if (s.size() >= 3) {
//            int k = 3;
//            for (int i = 0; i < s.size() - k + 1; ++i) {
//                string sub = s.substr(i, k);
//                set<char> my_set;
//                for (char c: sub){
//                    if (my_set.count(c)) break;
//                    else my_set.insert(c);
//                }
//                if (my_set.size() == 3) {
//                    ++ans;
//                }
//            }
//
//        }
//        return ans;
//    }
};

void read_data(string& s) {
    cin >> s;
    return;
}

int main() {
    string s;
    read_data(s);
    Solution solve;
    cout << solve.countGoodSubstrings(s);
    return 0;
}