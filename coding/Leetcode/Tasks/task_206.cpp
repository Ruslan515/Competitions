// https://leetcode.com/problems/reverse-linked-list/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 22.01.23.
//

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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;

//        ListNode* newHead(nullptr);
//        while (head != nullptr) {
//            int val = head->val;
//            ListNode* p = new ListNode(val);
//            p->next = newHead;
//            newHead = p;
//            head = head->next;
//        }
//        return newHead;
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