// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06
// Created by omega515 on 06.09.24.
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_set<int> st{nums.begin(), nums.end()};

        int val;
        while (head != nullptr) {
            val = head->val;
            if (st.find(val) != st.end()) {
                head = head->next;
            } else {
                break;
            }
        }

        ListNode *current = head->next, *prev = head;
        while (current) {
            val = current->val;
            if (st.find(val) != st.end()) {
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
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
    vector<int> nums;
    ListNode *head;
    ListNode *answer;
    Solution solve;

    nums = {1, 2, 3}, head = read_data({1, 2, 3, 4, 5});
    answer = read_data({4, 5});
    assert(answer == solve.modifiedList(nums, head));

    nums = {1}, head = read_data({1, 2, 1, 2, 1, 2});
    answer = read_data({2, 2, 2});
    assert(answer == solve.modifiedList(nums, head));

    nums = {5}, head = read_data({1, 2, 3, 4});
    answer = read_data({1, 2, 3, 4});
    assert(answer == solve.modifiedList(nums, head));

    return 0;
}