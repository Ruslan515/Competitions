// https://leetcode.com/problems/find-the-town-judge/
// Created by ruslan515 on 24.01.23.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) {
            return 1;
        }
        int ans = -1;
        if (trust.size() == 1) {
            ans = trust[0][1];
            return ans;
        }
        map<int, int> mp_a;
        map<int, int> mp_b;
        for(vector<int> v: trust) {
            int a = v[0];
            if (mp_a.count(a) == 0) {
                mp_a[a] = 1;
            } else {
                ++mp_a[a];
            }

            int b = v[1];
            if (mp_b.count(b) == 0) {
                mp_b[b] = 1;
            } else {
                ++mp_b[b];
            }
        }

        map<int, int> :: iterator it = mp_b.begin();
        for(; it != mp_b.end(); ++it) {
            int judge = it->first;
            int cnt = it->second;
            if (cnt == n - 1 && mp_a.count(judge) == 0) {
                ans = judge;
                break;
            }
        }
        return ans;
    }
};


void read_data(int& n, vector<vector<int>>& trust) {
    cin >> n;
    int x;
    cin >> x;
    int a, b;
    for (int i = 0; i < x; ++i) {
        vector<int> t;
        cin >> a >> b;
        t.push_back(a);
        t.push_back(b);
        trust.push_back(t);
    }
    return;
}

int main() {
    int n;
    vector<vector<int>> trust;
    read_data(n, trust);
    Solution solve;
    cout << solve.findJudge(n, trust);

    return 0;
}