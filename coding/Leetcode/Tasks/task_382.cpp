// https://leetcode.com/problems/linked-list-random-node/
// Created by ruslan515 on 10.03.23.
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
    ListNode *root;
    vector<int> v;
    int v_size = 0;
    int start_idx = 0;
    int end_idx = 0;

    Solution(ListNode *head) {
        root = head;
        while (root != nullptr) {
            int val = root->val;
            v.push_back(val);
            root = root->next;
        }
        v_size = v.size();
        end_idx = v_size - 1;
    }

    int getRandom() {
        int random_idx = start_idx + (rand() % (end_idx - start_idx + 1));
        int val = v[random_idx];
        return val;
    }
};

void read_data(ListNode *&first, ListNode *&last) {
    int temp;
    while (cin >> temp) {
        ListNode *p = new ListNode(temp);
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
    ListNode *head(nullptr);
    ListNode *last(nullptr);
    read_data(head, last);
    Solution *solve = new Solution(head);
    int ans = solve->getRandom();
    cout << ans << "\n";

    return 0;
}