// https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22
// Created by omega515 on 22.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<string> answer;
        priority_queue<pair<int, string >> pq;
        int n = names.size();
        for (int i = 0; i < n; ++i) {
            pq.push({heights[i], names[i]});
        }
        pair<int, string> pr;
        for (int i = 0; i < n; ++i) {
            pr = pq.top();
            pq.pop();
            answer.push_back(pr.second);
        }

        return answer;
    }
};

int main() {
    vector<string> names;
    vector<int> heights;
    vector<string> answer;
    Solution solve;

    names = {"Mary", "John", "Emma"}, heights = {180, 165, 170};
    answer = {"Mary", "Emma", "John"};
    assert(answer == solve.sortPeople(names, heights));

    names = {"Alice", "Bob", "Bob"}, heights = {155, 185, 150};
    answer = {"Bob", "Alice", "Bob"};
    assert(answer == solve.sortPeople(names, heights));

    return 0;
}
