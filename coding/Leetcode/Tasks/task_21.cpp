// https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 23.01.23.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return list1;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr){
            return list1;
        }
        ListNode* ans = new ListNode();
        ListNode* tail = ans;
        while (list1 != nullptr && list2 != nullptr) {
            int val1 = list1->val;
            int val2 = list2->val;

            if (val1 < val2) {
                tail->val = val1;
                list1 = list1->next;
            } else {
                tail->val = val2;
                list2 = list2->next;
            }
            ListNode* p = new ListNode();
            tail->next = p;
            tail = p;
        }
        if (list1 == nullptr) {
            tail->val = list2->val;
            tail->next = list2->next;
        } else {
            tail->val = list1->val;
            tail->next = list1->next;
        }

        return ans;
    }
};


void read_data(ListNode*& list1, ListNode*&list2) {
    int n, m;
    cin >> n >> m;
    int temp;
    ListNode* node;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        ListNode *p = new ListNode(temp);
        if (list1 == nullptr) {
            list1 = p;
            node = p;
        } else {
           node->next = p;
           node = p;
        }
    }

    for (int i = 0; i < m; ++i){
        cin >> temp;
        ListNode *p = new ListNode(temp);
        if (list2 == nullptr) {
            list2 = p;
            node = p;
        } else {
            node->next = p;
            node = p;
        }
    }

    return;
}

int main() {
    ListNode* list1(nullptr);
    ListNode* list2(nullptr);
    read_data(list1, list2);
    Solution solve;
    ListNode* ans(nullptr);
    ans = solve.mergeTwoLists(list1, list2);
    return 0;
}