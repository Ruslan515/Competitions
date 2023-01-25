// https://leetcode.com/problems/remove-duplicates-from-sorted-list/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 25.01.23.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail = new ListNode();
        tail = head;
        while (tail != nullptr) {
            while (tail->next != nullptr && tail->val == tail->next->val) {
                tail->next = tail->next->next;
            }
            tail = tail->next;
        }

        return head;
    }
};

void read_data(ListNode*& head) {
    int temp;
    ListNode* last;
    while (cin >> temp) {
        ListNode* p = new ListNode(temp);
        if (head == nullptr) {
            head = p;
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
    ans = solve.deleteDuplicates(head);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}