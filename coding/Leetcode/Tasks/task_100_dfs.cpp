// https://leetcode.com/problems/same-tree/description/
// Created by ruslan515 on 23.04.23.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
            return false;
        }
        int val_p = p->val;
        int val_q = q->val;
        if (val_p != val_q) {
            return false;
        }

        if (p->left == nullptr && p->right == nullptr && q->left == nullptr && q->right == nullptr) {
            return true;
        }
        bool left = false;
        if ((p->left != nullptr && q->left != nullptr) || (p->left == nullptr && q->left == nullptr)) {
            left = isSameTree(p->left, q->left);
        } else {
            return left;
        }
        bool right = false;
        if ((p->right != nullptr && q->right != nullptr) || (p->right == nullptr && q->right == nullptr)) {
            right = isSameTree(p->right, q->right);
        } else {
            return right;
        }
        bool ans = left && right;
        return ans;
    }
};

void read_data(TreeNode *&p, TreeNode *&q) {
//    TreeNode *t1 = new TreeNode(2);
//    TreeNode *t2 = new TreeNode(3);
//    TreeNode *t3 = new TreeNode(1, t1, t2);
//    p = t3;
//
//    TreeNode *t4 = new TreeNode(2);
//    TreeNode *t5 = new TreeNode(3);
//    TreeNode *t6 = new TreeNode(1, t4, t5);
//    q = t6;

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(1, nullptr, t1);
    p = t3;

    TreeNode *t4 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(1, nullptr, t4);
    q = t6;

    return;
}

int main() {
    TreeNode *p;
    TreeNode *q;
    read_data(p, q);
    Solution solve;
    bool answer;

    answer = true;
    assert(solve.isSameTree(p, q) == answer);

    return 0;
}