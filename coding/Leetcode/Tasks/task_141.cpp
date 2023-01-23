// https://leetcode.com/problems/linked-list-cycle/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 22.01.23.
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
    bool hasCycle(ListNode *head) {
        bool ans = false;
        map<ListNode* , int> mp;
        while (head != nullptr) {
            if (mp.count(head) == 1) {
                ans = true;
                break;
            } else {
                mp[head] = 1;
            }
            head = head->next;
        }
        return ans;
    }
};

//class Solution {
//public:
//    bool hasCycle(ListNode *head) {
//        bool ans = true;
//        if (head == nullptr || head->next == nullptr) {
//            ans = false;
//            return ans;
//
//        }
//        int n = 10001;
//        for (int i = 0; i < n; ++i) {
//            if (head->next == nullptr) {
//                ans = false;
//                break;
//            }
//            head = head->next;
//        }
//
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    bool hasCycle(ListNode *head) {
//        bool ans = false;
//        if (head == nullptr || head->next == nullptr)
//            return ans;
//        map<pair<int, int>, int> mp;
//        while (head != nullptr) {
//            pair<int, int> p;
//            p.first = head->val;
//            if (head->next == nullptr) {
//                break;
//            }
//            p.second = head->next->val;
//            if (mp.count(p) == 0) {
//                mp[p] = 1;
//            } else {
//                ans = true;
//                break;
//            }
//            head = head->next;
//        }
//
//        return ans;
//    }
//};


void read_data(ListNode*& first, ListNode*& last) {
    int pos;
    cin >> pos;
    int temp;
    ListNode* loop;
    int i = 0;
    while (cin >> temp) {
        ListNode* p = new ListNode(temp);
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
    ListNode* first(nullptr);
    ListNode* last(nullptr);
    read_data(first, last);
    Solution solve;
    cout << solve.hasCycle(first);
    return 0;
}