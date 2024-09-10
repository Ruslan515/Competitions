// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10
// Created by omega515 on 10.09.24.
//

#include <bits/stdc++.h>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        ListNode *current = head;
        ListNode *next;
        int valCurr, valNext;
        int gcdV;
        while (current->next) {
            next = current->next;
            valCurr = current->val;
            valNext = next->val;
            gcdV = gcd(valCurr, valNext);
            ListNode * node = new ListNode(gcdV, next);
            current->next = node;
            current = next;
        }

        return head;
    }
};

ListNode *read_data(vector<int> nums) {
    ListNode *head = nullptr;
    ListNode *prev;
    for (int num: nums) {
        ListNode *current = new ListNode(num);
        if (head == nullptr) {
            head = current;
            prev = current;
        } else {
            prev->next = current;
            prev = current;
        }
    }


    return head;
}

int main() {
    int k;
    ListNode *head;
    ListNode *answer;
    Solution solve;


    head = read_data({18, 6, 10, 3});
    answer = read_data({18, 6, 6, 2, 10, 1, 3});
    assert(answer == solve.insertGreatestCommonDivisors(head));

    head = read_data({7});
    answer = read_data({7});
    assert(answer == solve.insertGreatestCommonDivisors(head));


    return 0;
}