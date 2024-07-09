// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08
// Created by omega515 on 08.07.24.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    int findTheWinner(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (n == 1) {
            return 1;
        }

        int answer = 0;
        ListNode *head = new ListNode(1);
        ListNode *prev = head, *curr;
        for (int i = 2; i < n + 1; ++i) {
            curr = new ListNode(i);
            prev->next = curr;
            prev = curr;
        }
        curr->next = head;
        curr = head;

        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < k - 1; ++i) {
                curr = curr->next;
                prev = prev->next;
            }
            curr = curr->next;
            prev->next = curr;
        }
        answer = curr->val;

        return answer;
    }
};

int main() {
    int n, k;
    int answer;
    Solution solve;

    n = 5, k = 2;
    answer = 3;
    assert(answer == solve.findTheWinner(n, k));

    n = 6, k = 5;
    answer = 1;
    assert(answer == solve.findTheWinner(n, k));

    return 0;
}
