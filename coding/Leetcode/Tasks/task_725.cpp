// https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08
// Created by omega515 on 08.09.24.
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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<ListNode *> answer;
        vector<ListNode *> tmp;
        while (head) {
            tmp.push_back(head);
            head = head->next;
        }
        int n = tmp.size();
        if (n <= k) {
            for (ListNode *node: tmp) {
                node->next = nullptr;
                answer.push_back(node);
            }
            for (int i = n; i < k; ++i) {
                answer.push_back(nullptr);
            }
        } else {
            int cnt = n / k;
            int d = n % k;
            ListNode *node;
            for (int i = 0; i < d; ++i) {
                int idx = i * (cnt + 1);
                node = tmp[idx];
                answer.push_back(node);
                for (int j = 0; j < cnt; ++j) {
                    node = node->next;
                }
                node->next = nullptr;
            }

            for (int i = d * (cnt + 1); i < n; i += cnt) {
                int idx = i;
                node = tmp[idx];
                answer.push_back(node);
                for (int j = 0; j < (cnt - 1) && node != nullptr; ++j) {
                    node = node->next;
                }
                node->next = nullptr;

            }

        }


        return answer;
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
    vector<ListNode *> answer;
    Solution solve;
    vector<vector<int>> tmp;

//    head = read_data({1, 2, 3});
//    k = 5;
//    answer = {};
//    vector<vector<int>> tmp{{1},
//                            {2},
//                            {3},
//                            {},
//                            {}};
//    for (vector<int> v: tmp) {
//        answer.push_back(read_data(v));
//    }
//    assert(answer == solve.splitListToParts(head, k));

    head = read_data({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    k = 3;
    answer = {};
    tmp = {{1, 2, 3, 4},
           {5, 6, 7},
           {8, 9, 10}};
    for (vector<int> v: tmp) {
        answer.push_back(read_data(v));
    }
    assert(answer == solve.splitListToParts(head, k));

    head = read_data({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    k = 3;
    answer = {};
    tmp = {{1, 2,  3, 4},
           {5, 6,  7, 8},
           {9, 10, 11}};
    for (vector<int> v: tmp) {
        answer.push_back(read_data(v));
    }
    assert(answer == solve.splitListToParts(head, k));

    return 0;
}