// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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

//class Solution {
//public:
//    int pairSum(ListNode *head) {
//        ListNode *slow, *fast;
//        int answer = -1;
//        slow = head;
//        fast = head;
//        stack<int> st;
//        int val;
//        while (fast != nullptr && fast->next != nullptr) {
//            val = slow->val;
//            st.push(val);
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        int curr, sums;
//        while (slow != nullptr) {
//            curr = slow->val;
//            val = st.top();
//            st.pop();
//            sums = curr + val;
//            answer = max(answer, sums);
//            slow = slow->next;
//        }
//
//        return answer;
//    }
//};

class Solution {
public:
    int pairSum(ListNode *head) {
        ListNode *slow, *fast;
        int answer = -1;
        slow = head;
        fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = nullptr, *nextNode;
        while (slow != nullptr) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        while (prev != nullptr){
            answer = max(answer, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }
        return answer;
    }
};

int main() {
    ListNode *head;
    int answer;
    Solution solve;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;

    t5 = new ListNode(5);
    t4 = new ListNode(4, t5);
    t2 = new ListNode(2, t4);
    t1 = new ListNode(1, t2);
    head = t1;
    answer = 6;
    assert(answer == solve.pairSum(head));

    t5 = new ListNode(4);
    t4 = new ListNode(2, t5);
    t2 = new ListNode(2, t4);
    t1 = new ListNode(3, t2);
    head = t1;
    answer = 7;
    assert(answer == solve.pairSum(head));

    t2 = new ListNode(1);
    t1 = new ListNode(10000, t2);
    head = t1;
    answer = 10001;
    assert(answer == solve.pairSum(head));

    return 0;
}