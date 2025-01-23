// https://leetcode.com/contest/weekly-contest-388/problems/shortest-uncommon-substring-in-an-array/
// Created by omega515 on 10.03.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<string> createSubs(vector<string> &arr, int idx) {
        set<string> setStr;
        int n = arr.size();
        for (int k = 0; k < n; ++k) {
            if (k == idx) {
                continue;
            }
            string s = arr[k], tmp;
            int size = s.size();
            for (int i = 0; i < size; ++i) {
                for (int j = 1; j < size - i + 1; ++j) {
                    tmp = s.substr(i, j);
                    setStr.insert(tmp);
                }
            }
        }


        return setStr;
    }

    vector<string> shortestSubstrings(vector<string> &arr) {
        vector<string> answer;
        int n = arr.size();
        string s;
        for (int k = 0; k < n; ++k) {
            s = arr[k];
            int sizeS = s.size();
            set<string> setStr = createSubs(arr, k);
            int minSize = INT_MAX;
            string minStr = "", tmp;
            for (int i = 0; i < sizeS; ++i) {
                bool label = true;
                for (int j = 1; j < sizeS - i + 1; ++j) {
                    tmp = s.substr(i, j);
                    bool check = setStr.find(tmp) == setStr.end();
                    if (check) {  // not exist
                        if (j < minSize) {
                            minStr = tmp;
                            minSize = minStr.size();
                        }
                        else if (j == minSize) {
                            if (minStr == "") {
                                minStr = tmp;
                                minSize = minStr.size();
                            } else {
                                if (tmp < minStr) {
                                    minStr = tmp;
                                    minSize = minStr.size();
                                }
                            }
                        }
                    }
                }
            }
            answer.push_back(minStr);
        }

        return answer;
    }
};

int main() {
    vector<string> arr, answer;
    Solution solve;

    arr = {"gfnt", "xn", "mdz", "yfmr", "fi", "wwncn", "hkdy"};
    answer = {"g", "x", "z", "r", "i", "c", "h"};
    assert(answer == solve.shortestSubstrings(arr));

    arr = {"abc", "bcd", "abcd"};
    answer = {"", "", "abcd"};
    assert(answer == solve.shortestSubstrings(arr));

    arr = {"cab", "ad", "bad", "c"};
    answer = {"ab", "", "ba", ""};
    assert(answer == solve.shortestSubstrings(arr));

    return 0;
}

