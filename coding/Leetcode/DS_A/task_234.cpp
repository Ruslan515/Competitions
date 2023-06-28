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
    bool isPalindrome(ListNode *head) {
        bool answer = true;
        if (head->next == nullptr) {
            return answer;
        }
        if (head->next->next == nullptr) {
            if ( head->val != head->next->val) {
                answer = false;
            }
            return answer;
        }
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = slow->next;
        prev = nullptr;
        ListNode *nextNode;
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        while (prev) {
            if (prev->val != head->val) {
                answer = false;
                break;
            }
            prev = prev->next;
            head = head->next;
        }

        return answer;
    }
};

int main() {
    ListNode *head;
    bool answer;
    Solution solve;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11, *t12;

    t4 = new ListNode(1);
    t3 = new ListNode(2, t4);
    t2 = new ListNode(1, t3);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = false;
    assert(answer == solve.isPalindrome(head));

    t4 = new ListNode(1);
    t3 = new ListNode(2, t4);
    t9 = new ListNode(3, t3);
    t2 = new ListNode(2, t9);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = true;
    assert(answer == solve.isPalindrome(head));

    t2 = new ListNode(2);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = false;
    assert(answer == solve.isPalindrome(head));

    t3 = new ListNode(1);
    t2 = new ListNode(2, t3);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = true;
    assert(answer == solve.isPalindrome(head));

    t4 = new ListNode(1);
    t3 = new ListNode(2, t4);
    t2 = new ListNode(2, t3);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = true;
    assert(answer == solve.isPalindrome(head));

    return 0;
}