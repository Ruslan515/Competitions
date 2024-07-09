// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05
// Created by omega515 on 05.07.24.
//

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> answer;
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        if (n < 4) {
            return {-1, -1};
        }
        vector<int> idx;
        for (int i = 1; i < n - 1; ++i) {
            bool condMin = (v[i] < v[i - 1] && v[i] < v[i + 1]);
            bool condMax = (v[i] > v[i - 1] && v[i] > v[i + 1]);
            if (condMax || condMin) {
                idx.push_back(i);
            }
        }
        int m = idx.size();
        if (m <= 1) {
            return {-1, -1};
        }
        int maxDistance = idx[m - 1] - idx[0];
        int minDistance = maxDistance;
        int diff;
        for (int i = 1; i < m; ++i) {
            diff = idx[i] - idx[i - 1];
            minDistance = min(diff, minDistance);
        }
        answer = {minDistance, maxDistance};

        return answer;
    }

};

void read_data(vector<int> h, ListNode *&head, ListNode *&curr) {
    int n = h.size();
    for (int i = 0; i < n; ++i) {
        ListNode *p = new ListNode(h[i]);
        if (curr == nullptr) {
            head = p;
            curr = p;
        } else {
            curr->next = p;
            curr = p;
        }
    }

    return;
}

int main() {
    ListNode *head(nullptr), *curr(nullptr);
    vector<int> inputV;
    vector<int> answer;
    Solution solve;


    head = nullptr;
    curr = nullptr;
    inputV = {2, 3, 3, 2};
    answer = {-1, -1};
    read_data(inputV, head, curr);
    assert(answer == solve.nodesBetweenCriticalPoints(head));


    head = nullptr;
    curr = nullptr;
    inputV = {5, 3, 1, 2, 5, 1, 2};
    answer = {1, 3};
    read_data(inputV, head, curr);
    assert(answer == solve.nodesBetweenCriticalPoints(head));

    head = nullptr;
    curr = nullptr;
    inputV = {3, 1};
    answer = {-1, -1};
    read_data(inputV, head, curr);
    assert(answer == solve.nodesBetweenCriticalPoints(head));

    head = nullptr;
    curr = nullptr;
    inputV = {1, 3, 2, 2, 3, 2, 2, 2, 7};
    answer = {3, 3};
    read_data(inputV, head, curr);
    assert(answer == solve.nodesBetweenCriticalPoints(head));

    return 0;
}