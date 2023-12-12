// https://leetcode.com/problems/add-two-numbers/description/?envType=featured-list&envId=top-interview-questions?envType=featured-list&envId=top-interview-questions
// Created by omega515 on 05.12.23.
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
    long long  create(ListNode *l) {
        long long  answer = 0;
        long long  val;
        long long  p = 1;
        while (l != nullptr) {
            val = l->val;
            val *= p;
            p *= 10;
            answer += val;
            l = l->next;
        }
        return answer;
    }

    ListNode *createList(long long  sumV) {
        ListNode *answer;
        vector<int> vals;
        while (sumV != 0) {
            int d = sumV % 10;
            vals.push_back(d);
            sumV /= 10;
        }
        reverse(vals.begin(), vals.end());
        ListNode *first = new ListNode(vals[0]);
        ListNode *second;
        for (int i = 1; i < vals.size(); ++i) {
            int val = vals[i];
            ListNode *second = new ListNode(val, first);
            first = second;
        }
        answer = first;

        return answer;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *answer;
        long long v1 = create(l1), v2 = create(l2);
        long long  sumV = v1 + v2;
        if (sumV == 0) {
            answer = new ListNode(0);

        } else {
            answer = createList(sumV);
        }


        return answer;
    }
};

int main() {
    ListNode *l1;
    ListNode *l2;
    ListNode *answer;
    Solution solve;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6;
    ListNode *t7, *t8, *t9;

    //============================================
//    t3 = new ListNode(0);
//    t1 = new ListNode(0);
//    answer = solve.addTwoNumbers(t3, t1);

    //============================================
    t3 = new ListNode(3);
    t2 = new ListNode(4, t3);
    t1 = new ListNode(2, t2);

    t6 = new ListNode(4);
    t5 = new ListNode(6, t6);
    t4 = new ListNode(5, t5);

    t9 = new ListNode(8);
    t8 = new ListNode(0, t9);
    t7 = new ListNode(7, t8);

    answer = t7;
    assert(answer == solve.addTwoNumbers(t1, t4));

    return 0;
}