// https://leetcode.com/problems/high-five/description/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 22.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        map<int, priority_queue<int>> mp;
        int n = items.size();
        int id, score;
        for (int i = 0; i < n; ++i) {
            id = items[i][0];
            score = items[i][1];
            mp[id].push(score);
        }
        n = mp.size();
        vector<vector<int>> answer;
        map<int, priority_queue<int>>::iterator it = mp.begin();
        int avg;
        for (; it != mp.end(); ++it) {
            id = it->first;
            avg = 0;
            for (int i = 0; i < 5; ++i) {
                avg += it->second.top();
                it->second.pop();
            }
            avg /= 5;
            answer.push_back({id, avg});
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> items;
    vector<vector<int>> answer;
    Solution solve;

    items = {{1, 91},
             {1, 92},
             {2, 93},
             {2, 97},
             {1, 60},
             {2, 77},
             {1, 65},
             {1, 87},
             {1, 100},
             {2, 100},
             {2, 76}};
    answer = {{1, 87},
              {2, 88}};
    assert(answer == solve.highFive(items));

    items = {{1, 100},
             {7, 100},
             {1, 100},
             {7, 100},
             {1, 100},
             {7, 100},
             {1, 100},
             {7, 100},
             {1, 100},
             {7, 100}};
    answer = {{1, 100},
              {7, 100}};
    assert(answer == solve.highFive(items));

    return 0;
}
