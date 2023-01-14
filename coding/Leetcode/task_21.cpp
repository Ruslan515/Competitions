// https://leetcode.com/problems/merge-two-sorted-lists/
// Created by ruslan515 on 14.01.23.
//

#include <iostream>
#include <vector>

using namespace std;

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
        int x1 = list1->val;
        int x2 = list2->val;
        ListNode* ans;

    }
};

void read_data(ListNode* list1, ListNode* list2) {
    int n;
    cin >> n;
    int temp;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        ListNode()
        list1->val = temp
    }
    int temp;
    while (cin >> temp)
        prices.push_back(temp);
    return;
}

int main() {
    ListNode* list1;
    ListNode* list2;
    read_data(list1, list2);
    Solution solve;
    cout << solve.maxProfit(prices);

    return 0;
}