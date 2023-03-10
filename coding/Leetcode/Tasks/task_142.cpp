// https://leetcode.com/problems/linked-list-cycle-ii/
// Created by ruslan515 on 09.03.23.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        map<ListNode *, int> mp;
        ListNode *prev = nullptr;
        while (head != nullptr) {
            if (mp.count(head) == 1) {
                prev = head;
                break;
            } else {
                mp[head] = 1;
            }
            head = head->next;
        }
        return prev;
    }
};


void read_data(ListNode *&first, ListNode *&last) {
    int pos;
    cin >> pos;
    int temp;
    ListNode *loop;
    int i = 0;
    while (cin >> temp) {
        ListNode *p = new ListNode(temp);
        if (first == nullptr) {
            first = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
        if (i == pos && pos != -1) {
            loop = p;
        }
        ++i;
    }
    if (pos != -1) {
        last->next = loop;
    }

    return;
}

int main() {
    ListNode *first(nullptr);
    ListNode *last(nullptr);
    read_data(first, last);
    Solution solve;
    ListNode *x = solve.detectCycle(first);

    return 0;
}