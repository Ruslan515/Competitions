// https://leetcode.com/problems/remove-linked-list-elements/?envType=study-plan&id=data-structure-i
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr)
            return head;
        ListNode* temp = new ListNode();
        ListNode* prev = new ListNode();
        temp = head;
        prev->next = head;
        while (temp != nullptr) {
            int val_temp = temp->val;
            if (val_temp == val) {
                prev->next = temp->next;
            } else {
                prev = prev->next;
            }
            temp = temp->next;
        }
        return head;
    }
};

void read_data(ListNode*& first, ListNode*& last, int& val) {
    cin >> val;
    int temp;
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
    int val;
    ListNode* head(nullptr);
    ListNode* last(nullptr);
    read_data(head, last, val);
    Solution solve;
    ListNode* ans = new ListNode();
    ans = solve.removeElements(head, val);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}