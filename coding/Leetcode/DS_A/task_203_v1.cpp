// https://leetcode.com/problems/remove-linked-list-elements/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 05.07.23.
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
    int getDecimalValue(ListNode *head) {
        int answer = 0;
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        int l = 1;
        for (int i = 0; i < v.size(); ++i) {
            answer += v[i] * l;
            l *= 2;
        }

        return answer;
    }
};

void read_data(ListNode *&first, ListNode *&last, int &val) {
    cin >> val;
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
    int val;
    ListNode *head(nullptr);
    ListNode *last(nullptr);
    read_data(head, last, val);
    Solution solve;
    ListNode *ans = new ListNode();
    ans = solve.removeElements(head, val);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}