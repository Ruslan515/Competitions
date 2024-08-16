// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
// Created by omega515 on 05.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string> &arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";
        unordered_set<string> unique;
        unordered_set<string> notUnique;
        for (string s: arr) {
            if (unique.find(s) != unique.end()) {
                unique.erase(s);
                notUnique.insert(s);
            } else if (notUnique.find(s) == notUnique.end()) {
                unique.insert(s);
            }

        }
        if (unique.size() == 0 || unique.size() < k) {
            return answer;
        }
        int i = 0;
        for (string s: arr) {
            if (unique.find(s) != unique.end()) {
                ++i;
                if (i == k) {
                    return s;
                }
            }
        }


        return answer;
    }
};


int main() {
    vector<string> arr;
    int k;
    string answer;
    Solution solve;

    arr = {"c", "c", "c", "exjk", "nbmg", "kgnas", "s", "oydx", "ghpao", "r",
           "ohdm", "fq", "ashgg", "mm", "cc", "mymy", "w",
           "t", "neb", "grjdb", "cukk", "ujyhn", "dq", "hhuo",
           "qu", "seslw", "ybulz", "iug", "rs", "kyfu", "krz", "nw",
           "txnn", "r", "zpuao", "sh", "rfc", "hgr",
           "jfia", "egm", "gmuuv", "gh", "x", "nfvgv", "ibo", "al", "wn",
           "o", "dyu", "zgkk", "gdzrf", "m", "ui",
           "xwsj", "zeld", "muowr", "d", "xgiu", "yfu"}, k = 19;
    answer = "dq";
    assert(answer == solve.kthDistinct(arr, k));

    arr = {"aaa", "aa", "a"}, k = 1;
    answer = "aaa";
    assert(answer == solve.kthDistinct(arr, k));

    arr = {"d", "b", "c", "b", "c", "a"}, k = 2;
    answer = "a";
    assert(answer == solve.kthDistinct(arr, k));

    arr = {"a", "b", "a"}, k = 3;
    answer = "";
    assert(answer == solve.kthDistinct(arr, k));

    return 0;
}
