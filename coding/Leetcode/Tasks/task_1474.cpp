// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 12.07.24.
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
    ListNode *deleteNodes(ListNode *head, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode *answer = head;

        ListNode *curr;
        while (head) {
            int i = 0;
            while (head && i < m - 1) {
                head = head->next;
                ++i;
            }
            if (head) {
                curr = head->next;
                i = 0;
                while (curr && i < n) {
                    head->next = curr->next;
                    curr = head->next;
                    ++i;
                }
                head = curr;
                cout << "n";
            }
        }

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

vector<int> toVector(ListNode *head) {
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

int main() {
    int n, m;
    ListNode *head(nullptr), *curr(nullptr);
    vector<int> inputV;
    vector<int> answer, res;
    Solution solve;


    head = nullptr;
    curr = nullptr;
    inputV = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, m = 2, n = 3;
    answer = {1, 2, 6, 7, 11, 12};
    read_data(inputV, head, curr);
    solve.deleteNodes(head, m, n);
    res = toVector(head);
    assert(answer == res);


    head = nullptr;
    head = nullptr;
    curr = nullptr;
    inputV = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, m = 1, n = 3;
    answer = {1, 5, 9};
    read_data(inputV, head, curr);
    solve.deleteNodes(head, m, n);
    res = toVector(head);
    assert(answer == res);

    return 0;
}