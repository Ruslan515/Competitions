// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// Created by ruslan515 on 19.02.23.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(3, t1, t2);

    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(6, nullptr, t4);
    TreeNode *t6 = new TreeNode(5, t3, t5);

    root = t6;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    cout << solve.lowestCommonAncestor(root, 2, 6);

    return 0;
}