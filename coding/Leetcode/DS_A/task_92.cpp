// https://leetcode.com/problems/reverse-linked-list-ii/description/
// Created by Ruslan Khalikov on 25.06.2023.
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head->next == nullptr) {
            return head;
        }
        if (left == right) {
            return head;
        }
        --left;
        --right;
        int len = right - left + 1;
        ListNode *current = head;
        while (left > 1) {
            current = current->next;
            --left;
        }

        ListNode *prev = nullptr, *nextNode, *last;
        if (len == 2) {
            nextNode = current->next;
            last = current->next->next;
            current->next = last;
            nextNode->next = current;
        }
        ListNode *start = current->next;

        prev = nullptr;
        while (right) {
            nextNode = start->next;
            start->next = prev;
            last = prev;
            prev = start;
            start = nextNode;
            --right;
        }
        current->next->next = nextNode;
        current->next = prev;

        return head;
    }
};

int main() {
    ListNode *head, *answer;
    Solution solve;
    int left, right;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11, *t12;

    t2 = new ListNode(5);
    t1 = new ListNode(3, t2);
    head = t1;

    t9 = new ListNode(3);
    t10 = new ListNode(5, t9);
    answer = t10;
    left = 1, right = 2;
    assert(answer == solve.reverseBetween(head, left, right));

//    t5 = new ListNode(5);
//    t4 = new ListNode(4, t5);
//    t3 = new ListNode(3, t4);
//    t2 = new ListNode(2, t3);
//    t1 = new ListNode(1, t2);
//    head = t1;
//
//    t6 = new ListNode(5);
//    t7 = new ListNode(2, t6);
//    t8 = new ListNode(3, t7);
//    t9 = new ListNode(4, t8);
//    t10 = new ListNode(1, t9);
//    answer = t10;
//    left = 2, right = 4;
//    assert(answer == solve.reverseBetween(head, left, right));

    return 0;
}