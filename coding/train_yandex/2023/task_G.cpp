// https://contest.yandex.ru/contest/8458/problems/G/
// Created by ruslan515 on 31.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_reachable(pair<int, int> start, pair<int, int> end, int k) {
        bool answer = false;
        int dist = abs(start.first  - end.first) + abs(start.second - end.second);
        if (dist <= k) {
            answer = true;
        }
        return answer;
    }

    int solving(int start, int end, vector<pair<int, int>> &v, int k) {
        int answer = -1;
        int n = v.size();
        vector<int> used(n, false);
        pair<int, int> target = v[end];
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(v[start], 0));
        used[start] = true;
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                pair<pair<int, int>, int>  x = q.front();
                q.pop();
                pair<int, int> current = x.first;
                int dist = x.second;
                if (current == target) {
                    return dist;
                }
                set<pair<int, int>> s(v.begin(), v.end());
                s.erase(current);
                set<pair<int, int>>::iterator it = s.begin();
                for (; it != s.end(); ++it) {
                    pair<int, int> to = *it;
                    if (is_reachable(current, to, k)) {
                        q.push(make_pair(to, dist + 1));
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    int k, start, end;
    cin >> k >> start >> end;
    Solution solve;
    cout << solve.solving(start, end, v, k);

    return 0;
}