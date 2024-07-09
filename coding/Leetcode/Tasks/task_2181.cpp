// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03
// Created by omega515 on 03.07.24.
//
/*
 * --test #1--
0
3
1
0
4
5
2
0
 * --test #2--

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
    ListNode *mergeNodes(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode *start = head, *end = head->next;
        ListNode *curr(nullptr), *answer(nullptr);
        int sum;
        while (end != nullptr) {
            sum = 0;
            while (end->val != 0) {
                sum += end->val;
                end = end->next;
            }
            ListNode *p = new ListNode(sum);
            if (curr == nullptr) {
                curr = p;
                answer = p;
            } else {
                curr->next = p;
                curr = p;
            }
            start = end;
            end = end->next;
        }

        return answer;
    }

};

void read_data(ListNode *&head, ListNode *&curr) {
    int temp;
    while (cin >> temp) {
        ListNode *p = new ListNode(temp);
        if (curr == nullptr) {
            head = p;
            curr = p;
        } else {
            curr->next = p;
            curr = p;
        }
    }

    return;
}

int main() {
    ListNode *head(nullptr), *curr(nullptr);
    read_data(head, curr);

    Solution solve;
    solve.mergeNodes(head);

    return 0;
}