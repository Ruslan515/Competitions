// https://leetcode.com/problems/merge-k-sorted-lists/
// Created by ruslan515 on 12.03.23.
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

    ListNode* mergeRecursive(vector<ListNode*> & lists, int start, int end) {
        int n = end - start;
        if (n == 0) {
            return lists[start];
        }
        int d = n / 2;
        ListNode* left = mergeRecursive(lists, start, d);
        ListNode* right = mergeRecursive(lists, d + 1, end);
        ListNode * ans = mergeTwoLists(left, right);
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode*> copy_lists;
        for (int i = 0; i < k; ++i) {
            if (lists[i] != nullptr) {
                copy_lists.push_back(lists[i]);
            }
        }
        k = copy_lists.size();
        if (k == 0) {
            return nullptr;
        }

        ListNode * ans = mergeRecursive(copy_lists, 0, k - 1);
        return ans;
    }
};


void read_data(vector<ListNode*>& lists) {
    int k, n;
    cin >> k;
    for(int z = 0; z < k; ++z) {
        cin >> n;
        int temp;
        ListNode* head = nullptr;
        ListNode* node;
        for (int i = 0; i < n; ++i){
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
        lists.push_back(head);
    }

    return;
}

int main() {
    vector<ListNode*> lists;
    read_data(lists);
    Solution solve;
    ListNode* ans(nullptr);
    ans = solve.mergeKLists(lists);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}