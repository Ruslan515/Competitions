// https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Created by ruslan515 on 09.04.23.
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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode *next = head->next;
        head->next = next->next;
        next->next = head;
        ListNode * temp = swapPairs(head->next);
        head->next = temp;
        return next;
    }
};


void read_data(ListNode *head) {
    int n;
    cin >> n;
    int temp;
    ListNode *node;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        ListNode *p = new ListNode(temp);
        if (head == nullptr) {
            head = p;
            node = p;
        } else {
            node->next = p;
            node = p;
        }
    }
}


int main() {
    ListNode *head(nullptr);
    read_data(head);
    Solution solve;
    ListNode *ans(nullptr);
    ans = solve.swapPairs(head);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}