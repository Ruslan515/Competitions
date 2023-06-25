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
        int len = right - left + 1;
        ListNode *current;
        while (left) {
            current = current->next;
            --left;
        }

        ListNode *start = current;

    }
};

int main() {
    ListNode *head, *answer;
    Solution solve;
    int left, right;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11, *t12;

    t5 = new ListNode(5);
    t4 = new ListNode(4, t5);
    t3 = new ListNode(3, t4);
    t2 = new ListNode(2, t3);
    t1 = new ListNode(1, t2);
    head = t1;

    t6 = new ListNode(5);
    t7 = new ListNode(2, t5);
    t8 = new ListNode(3, t4);
    t9 = new ListNode(4, t3);
    t10 = new ListNode(1, t2);
    answer = t10;
    left = 2, right = 4;
    assert(answer == solve.reverseBetween(head, left, right));

    return 0;
}