// https://leetcode.com/problems/add-two-numbers-ii/
// Created by Ruslan Khalikov on 17.07.2023.
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
    vector<int> fromListToVec(ListNode *l) {
        vector<int> ans;
        int val;
        while (l) {
            val = l->val;
            ans.push_back(val);
            l = l->next;
        }
        return ans;
    }

    void sumD(vector<int> &v, vector<int> &ans, int d, int start, int end) {
        int temp;
        for (int i = start; i < end; ++i) {
            temp = v[i] + d;
            if (temp >= 10) {
                temp %= 10;
                d = 1;
            } else {
                d = 0;
            }
            ans.push_back(temp);
        }
        if (d == 1) {
            ans.push_back(d);
        }
    }

    vector<int> sum2vec(vector<int> v1, vector<int> v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        int nMin = min(n1, n2), nMax = max(n1, n2);
        vector<int> ans;
        int temp, d = 0;
        for (int i = 0; i < nMin; ++i) {
            temp = v1[i] + v2[i] + d;
            if (temp >= 10) {
                temp %= 10;
                d = 1;
            } else {
                d = 0;
            }
            ans.push_back(temp);
        }
        if (n1 > n2) {
            sumD(v1, ans, d, nMin, nMax);
        } else {
            sumD(v2, ans, d, nMin, nMax);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    ListNode *fromVecToList(vector<int> v) {
        ListNode *prev, *head;
        prev = new ListNode(0);
        head = prev;
        for (int i = 0; i < v.size(); ++i) {
            ListNode *current = new ListNode(v[i]);
            prev->next = current;
            prev = current;
        }
        head = head->next;
        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ios::sync_with_stdio(false);
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        vector<int> v1, v2;
        v1 = fromListToVec(l1);
        v2 = fromListToVec(l2);
        vector<int> sumVec = sum2vec(v1, v2);
        ListNode *ans = fromVecToList(sumVec);
        return ans;
    }
};

int main() {
    ListNode *l1, *l2, *answer;
    Solution solve;
    ListNode *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11;

    t4 = new ListNode(3);
    t3 = new ListNode(4, t4);
    t2 = new ListNode(2, t3);
    t1 = new ListNode(7, t2);
    l1 = t1;

    t5 = new ListNode(4);
    t6 = new ListNode(6, t5);
    t7 = new ListNode(5, t6);
    l2 = t7;

    t8 = new ListNode(7);
    t9 = new ListNode(0, t8);
    t10 = new ListNode(8, t9);
    t11 = new ListNode(7, t10);
    answer = t11;
    assert(answer == solve.addTwoNumbers(l1, l2));

    return 0;
}