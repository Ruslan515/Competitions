// https://leetcode.com/problems/k-closest-points-to-origin/description/
// Created by ruslan515 on 04.07.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(false);
        cin.tie(0);

    }
    long long getL2(int x, int y) {
        long long answer = x * x + y * y;
        return answer;
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<pair<long long, vector<int>>, vector<pair<long long, vector<int>>>, greater<pair<long long, vector<int>>>> pq;
        long long dist;
        for (auto point: points) {
            dist = getL2(point[0], point[1]);
            pq.push({dist, point});
        }
        vector<vector<int>> answer;
        for (int i = 0; i < k; ++i) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> points, answer;
    int k;
    Solution solve;

    points = {{9997, 9997},
              {9996, 9998}};
    k = 1;
    answer = {{9997, 9997}};
    assert(answer == solve.kClosest(points, k));

    points = {{1,  3},
              {-2, 2}}, k = 1;
    answer = {{-2, 2}};
    assert(answer == solve.kClosest(points, k));

    points = {{3,  3},
              {5,  -1},
              {-2, 4}}, k = 2;
    answer = {{3,  3},
              {-2, 4}};
    assert(answer == solve.kClosest(points, k));

    return 0;
}