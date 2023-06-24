// https://leetcode.com/problems/middle-of-the-linked-list/description/
// Created by ruslan515 on 24.06.23.
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
    ListNode *middleNode(ListNode *head) {
        ListNode *answer = head;
        int count = 0;
        while (head != nullptr) {
            head = head->next;
            ++count;
        }
        count /= 2;
        while (count != 0 && answer != nullptr) {
            answer = answer->next;
            --count;
        }

        return answer;
    }
};

int main() {
    ListNode *head, *answer;
    Solution solve;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;

    t5 = new ListNode(5);
    t4 = new ListNode(4, t5);
    t3 = new ListNode(3, t4);
    t2 = new ListNode(2, t3);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = t3;
    assert(answer == solve.middleNode(head));

    t6 = new ListNode(6);
    t5 = new ListNode(5, t6);
    t4 = new ListNode(4, t5);
    t3 = new ListNode(3, t4);
    t2 = new ListNode(2, t3);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = t4;
    assert(answer == solve.middleNode(head));


    return 0;
}