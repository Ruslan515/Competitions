// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/description/?envType=weekly-question&envId=2024-07-08
// Created by omega515 on 13.07.24.
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
    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode *answer = head;
        unordered_map<int, int> mp;
        while (head) {
            ++mp[head->val];
            head = head->next;
        }
        head = answer;
        int key, val;
        while (head) {
            key = head->val;
            val = mp[key];
            if (val > 1) {
                head = head->next;
            } else {
                break;
            }
        }
        if (!head) {
            return nullptr;
        }
        answer = head;
        ListNode *prev = head;
        while (true) {
            head = head->next;
            if (!head) {
                break;
            }
            key = head->val;
            val = mp[key];
            if (val > 1) {
                prev->next = head->next;
            } else {
                prev = head;
            }
        }


        return answer;
    }

};

void read_data(vector<int> h, ListNode *&head, ListNode *&curr) {
    int n = h.size();
    for (int i = 0; i < n; ++i) {
        ListNode *p = new ListNode(h[i]);
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

vector<int> toVector(ListNode *head) {
    vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

int main() {
    ListNode *head(nullptr), *curr(nullptr);
    vector<int> inputV;
    vector<int> answer, res;
    Solution solve;

    head = nullptr;
    curr = nullptr;
    inputV = {2, 1, 1, 2};
    answer = {};
    read_data(inputV, head, curr);
    curr = solve.deleteDuplicatesUnsorted(head);
    res = toVector(curr);
    assert(answer == res);

    head = nullptr;
    curr = nullptr;
    inputV = {1, 2, 3, 2};
    answer = {1, 3};
    read_data(inputV, head, curr);
    curr = solve.deleteDuplicatesUnsorted(head);
    res = toVector(curr);
    assert(answer == res);

    head = nullptr;
    curr = nullptr;
    inputV = {3, 2, 2, 1, 3, 2, 4};
    answer = {1, 4};
    read_data(inputV, head, curr);
    curr = solve.deleteDuplicatesUnsorted(head);
    res = toVector(curr);
    assert(answer == res);

    return 0;
}