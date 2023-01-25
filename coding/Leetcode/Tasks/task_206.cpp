// https://leetcode.com/problems/reverse-linked-list/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 22.01.23.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <map>

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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead(nullptr);
        ListNode* tail(nullptr);
        while (head != nullptr) {
            int val = head->val;
            ListNode

            head = head->next;
        }

        return head;
    }
};

void read_data(ListNode*& first) {
    int temp;
    ListNode* last;
    while (cin >> temp) {
        ListNode* p = new ListNode(temp);
        if (first == nullptr) {
            first = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
    }

    return;
}

int main() {
    ListNode* head(nullptr);
    ListNode* last(nullptr);
    read_data(head);
    Solution solve;
    ListNode* ans = new ListNode();
    ans = solve.reverseList(head);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}